/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:50:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:49:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	do_put_pixel(char *addr, int color)
{
	*(unsigned int *)addr = color;
}

static int	is_edge_pixel(t_pixel px)
{
	if (px.x == 0 
		|| px.x == 19 
		|| px.y == 0 
		|| px.y == 19)
		return (1);
	return (0);
}

static void	put_pixel(t_pixel px, t_nav *nav, t_image *img)
{
	char	*addr;
	int		color;

	addr = put_color_label_get_addr(px, nav, img);
	if (is_edge_pixel(px))
		color = BLACK;
	else
		color = conv_col(nav->cont.obj->color);
	do_put_pixel(addr, color);
}

static void	put_line(int y, t_nav *nav, t_image *img)
{
	int	x;

	x = -1;
	while (x++ < 19)
		put_pixel(pix_l(x, y), nav, img);
}

void	put_color_label(t_nav *nav, t_image *img)
{
	int		y;

	y = -1;
	while (y++ < 19)
		put_line(y, nav, img);
}
