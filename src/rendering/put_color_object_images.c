/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_object_images.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:38:34 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 20:23:56 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void	fill_vertically(t_hit *hit, t_obj *obj, t_data *dt)
{
	int		counter;

	set(&counter);
	while (there_are_more_sub_pixels(counter, dt))
	{
		put_color_in_obj_image_pixel_vertical(hit, obj, counter, dt);
		increase(&counter);
	}
}

static void	fill_darker_horizontally(t_hit *hit, t_obj *obj, t_data *dt)
{
	int		counter;

	set(&counter);
	while (there_are_more_sub_pixels(counter, dt))
	{
		put_color_in_obj_image_pixel_horizontal(hit, obj, counter, dt);
		increase(&counter);
	}
}

static void	put_color_in_object_image(t_hit *hit, t_obj *obj, t_data *dt)
{
	if (ray_hit_object(obj, dt))
		fill_vertically(hit, obj, dt);
	else
		fill_darker_horizontally(hit, obj, dt);
}

void	put_color_in_object_images(t_hit *hit, t_data *dt)
{
	t_obj	*obj;

	obj = first_object(dt);
	while (obj)
	{
		put_color_in_object_image(hit, obj, dt);
		next_object(&obj);
	}
}
