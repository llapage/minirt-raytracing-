/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:45:36 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 17:30:20 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static void	do_put_graphic(int offset, t_graphic *gr, t_image *img);
static void	put_line(int offset, int *pixel_nb, t_graphic *gr, t_image *img);
static void	put_pixel(int offset, int *pixel_nb, t_graphic *gr, t_image *img);

void	put_graphic(t_graphic *gr, t_pixel top_left, t_image *img)
{
	int	offset;

	offset = top_left.y * img->size_line + top_left.x * img->size_pixel;
	do_put_graphic(offset, gr, img);
}

static void	do_put_graphic(int offset, t_graphic *gr, t_image *img)
{
	int	line;
	int	pixel_nb;

	line = 0;
	pixel_nb = 0;
	while (line < gr->height)
	{
		put_line(offset, &pixel_nb, gr, img);
		offset += img->size_line;
		line++;
	}
}

static void	put_line(int offset, int *pixel_nb, t_graphic *gr, t_image *img)
{
	int	col;

	col = 0;
	while (col < gr->width)
	{
		put_pixel(offset, pixel_nb, gr, img);
		offset += img->size_pixel;
		(*pixel_nb)++;
		col++;
	}
}

static void	put_pixel(int offset, int *pixel_nb, t_graphic *gr, t_image *img)
{
	char	*address;
	int		color;

	address = img->data_addr + offset;
	color = gr->pixel_int[*pixel_nb];
	if (offset < (S_WIDTH * S_HEIGHT * img->size_pixel))
		put_pixel_at(address, color);
}
