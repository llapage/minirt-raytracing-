/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:42 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:18:06 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/image.h"

char	*pixel_address(t_pixel pixel, t_image *img)
{
	char	*address;
	int		offset;

	offset = pixel.y * img->size_line + pixel.x * img->size_pixel; 
	address = img->data_addr + offset;
	return (address);
}

t_mlx_string	*new_mlx_string(char *string, t_pixel position, 
			unsigned int color)
{
	t_mlx_string	*mlx_string;

	if (string == NULL)
		return (NULL);
	mlx_string = malloc(sizeof(t_mlx_string));
	if (mlx_string == NULL)
		return (NULL);
	mlx_string->string = string;
	mlx_string->position = position;
	mlx_string->color = color;
	return (mlx_string);
}

t_pixel	pix_l(int x, int y)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	return (p);
}
