/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:38:34 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:48:40 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	put_color_in_obj_image_pixel_vertical(
		t_hit *hit, t_obj *obj, int i, t_data *dt)
{
	my_mlx_pixel_put(obj->render_image_pointer, (dt->px.x), 
		dt->px.y + i + dt->vp->b_offs, conv_col(hit->color));
}

void	put_color_in_obj_image_pixel_horizontal(
		t_hit *hit, t_obj *obj, int i, t_data *dt)
{
	my_mlx_pixel_put(obj->render_image_pointer, (dt->px.x) + i, 
		dt->px.y + dt->vp->b_offs, col_darken(hit->color));
}

void	put_color_in_main_image_pixel(t_hit *hit, int i, t_data *dt)
{
	my_mlx_pixel_put(dt->render_image_pointer, dt->px.x + i, 
		dt->px.y + dt->vp->b_offs, conv_col(hit->color));
}

void	set(int *counter)
{
	*counter = 0;
}

void	increase(int *counter)
{
	(*counter)++;
}
