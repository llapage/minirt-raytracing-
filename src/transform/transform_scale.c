/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:58:55 by llapage           #+#    #+#             */
/*   Updated: 2023/12/29 22:33:15 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

void	scale(t_data *dt, int keycode, t_pixel ptr)
{
	t_obj	*obj;

	obj = object_under_pointer(ptr, dt);
	if (obj == NULL)
		return ;
	object_selection(obj, dt);
	if (obj->type == SPHERE && keycode == SCROLL_DOWN_BUTTON)
		scale_sphere(dt, 1.1);
	else if (obj->type == SPHERE && keycode == SCROLL_UP_BUTTON)
		scale_sphere(dt, 0.9);
	else if (obj->type == CYL && keycode == SCROLL_DOWN_BUTTON)
		scale_width_cyl(dt, 1.1);
	else if (obj->type == CYL && keycode == SCROLL_UP_BUTTON)
		scale_width_cyl(dt, 0.9);
	edit_mode(dt);
	render(dt);
}

void	scale_sphere(t_data *dt, float ratio)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)current_shape(dt);
	save_state(sphere, SPHERE, dt);
	sphere->diameter = sphere->diameter * ratio;
}

void	scale_width_cyl(t_data *dt, float ratio)
{
	dt->curr_obj->shape.sphere->diameter
		= dt->curr_obj->shape.cyl->diameter * ratio;
}

void	scale_height_cyl(t_data *dt, float ratio)
{
	dt->curr_obj->shape.sphere->diameter
		= dt->curr_obj->shape.cyl->height * ratio;
}
