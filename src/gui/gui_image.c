/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:42 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 00:56:53 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gui.h"

void	show_str(t_data *dt, char *str, t_pixel px, int color)
{
	mlx_string_put(dt->mlx, dt->win, px.x, px.y, color, str); 
}

void	clear_image(t_image *img, t_data *dt)
{
	*(t_screen *)(img->data_addr) = dt->blk_scrn;
}

void	clear_stub_images(t_data *dt)
{
	t_obj	*obj;

	clear_image(dt->stub_render_image, dt);
	obj = dt->scene->obj;
	while (obj)
	{
		clear_image(obj->stub_render_image, dt);
		obj = obj->next;
	}
}

void	point_to_stub_render_images(t_data *dt)
{
	t_obj	*obj;

	dt->render_image_pointer = dt->stub_render_image;
	obj = dt->scene->obj;
	while (obj)
	{
		obj->render_image_pointer = obj->stub_render_image;
		obj = obj->next;
	}
}

void	point_to_full_render_images(t_data *dt)
{
	t_obj	*obj;

	dt->render_image_pointer = dt->full_render_image;
	obj = dt->scene->obj;
	while (obj)
	{
		obj->render_image_pointer = obj->full_render_image;
		obj = obj->next;
	}
}
