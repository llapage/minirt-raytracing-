/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:42 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 16:15:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/image.h"

void	put_pixel_at(void *address, unsigned int color)
{
	*(unsigned int *)address = color;
}

void	put_mlx_string(void *mlx_ptr, void *win_ptr, t_mlx_string *mlx_string)
{
	char			*string;
	t_pixel			position;
	unsigned int	color;

	string = mlx_string->string;
	position = mlx_string->position;
	color = mlx_string->color;
	mlx_string_put(mlx_ptr, win_ptr, position.x, position.y, color, string);
}

void	put_mlx_string_list(void *mlx_ptr, void *win_ptr,
		t_list *mlx_string_list)
{
	t_list			*mlx_string_list_ptr;
	t_mlx_string	*mlx_string_ptr;

	mlx_string_list_ptr = mlx_string_list;
	while (mlx_string_list_ptr)
	{
		mlx_string_ptr = (t_mlx_string *)mlx_string_list_ptr->content;
		put_mlx_string(mlx_ptr, win_ptr, mlx_string_ptr);
		mlx_string_list_ptr = mlx_string_list_ptr->next;
	}
}

void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*address;
	t_pixel	pixel;

	pixel = pix_l(x, y);
	if (out_of_bounds(pixel) == FALSE)
	{
		address = pixel_address(pixel, img);
		put_pixel_at(address, color);
	}
}
