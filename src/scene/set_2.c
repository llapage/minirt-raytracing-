/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 16:20:17 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	range_wrap_scene(t_scene *scene)
{
	range_wrap_cam(scene->cam);
	range_wrap_objects(scene);
	range_wrap_lights(scene);
}

void	range_wrap_cam(t_cam *cam)
{
	float_wrap(&cam->dir.x, -1.0, 1.0);
	float_wrap(&cam->dir.y, -1.0, 1.0);
	float_wrap(&cam->dir.z, -1.0, 1.0);
	uint_wrap(&cam->fov, 0, 180);
}

void	range_wrap_objects(t_scene *scene)
{
	t_obj	*object;
	char	type;

	object = scene->obj;
	while (object != NULL)
	{
		type = object->type;
		range_wrap_object_commons(object);
		if (type == CYL)
			range_wrap_cyl(object->shape.cyl);
		else if (type == SPHERE)
			range_wrap_sphere(object->shape.sphere);
		else if (type == PLANE)
			range_wrap_plane(object->shape.plane);
		else if (type == CONE)
			range_wrap_cone(object->shape.cone);
		next_object(&object);
	}
}

void	range_wrap_lights(t_scene *scene)
{
	t_lux	*light;
	char	type;

	light = scene->lux;
	while (light != NULL)
	{
		range_wrap_light_commons(light);
		type = light->type;
		if (type == DIRECTIONAL)
			range_wrap_dir(light->src.dir);
		next_light(&light);
	}
}
