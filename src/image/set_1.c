/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:42 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 00:13:24 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/image.h"

void	new_image(void *mlx, t_image *img, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->size_pixel = img->bits_per_pixel / 8;
	img->size_image = width * height * img->size_pixel;
}

void	copy_image(t_image *dst, t_image *src)
{
	*(t_screen *)(dst->data_addr) = *(t_screen *)(src->data_addr); 
}

void	set_image_pointer_to_pointer(t_image ***pointer_to_pointer,
		t_image **pointer)
{
	*pointer_to_pointer = pointer;
}

void	black_and_white(t_image *img)
{
	int	i;
	int	color;
	int	b_and_w;

	i = -1; 
	while (i++ < img->size_image - 1)
	{
		color = *(unsigned int *)(img->data_addr + i); 
		b_and_w = col_bw(color);
		*(img->data_addr + i) = 0 | b_and_w << 16 | b_and_w << 8 | b_and_w;
	}
}
