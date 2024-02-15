/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:44:52 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static int	new_obj_error(t_obj *obj)
{
	free(obj->full_render_image);
	free(obj->stub_render_image);
	free(obj);
	return (FAILURE);
}

static void	new_obj_2(t_obj *obj, t_scene *scene)
{
	obj->fill = SOLID_FILL;
	obj->surface = SMOOTH_SURFACE;
	obj->id = scene->nb_obj;
	obj->next = scene->obj;
	scene->obj = obj;
}

static int	malloc_object(t_obj *obj, int type)
{
	obj->shape.plane = NULL;
	obj->shape.sphere = NULL;
	obj->shape.cyl = NULL;
	obj->shape.cone = NULL;
	if (type == PLANE)
		obj->shape.plane = malloc(sizeof(t_plane));
	else if (type == SPHERE)
		obj->shape.sphere = malloc(sizeof(t_sphere));
	else if (type == CYL)
		obj->shape.cyl = malloc(sizeof(t_cyl));
	else if (type == CONE)
		obj->shape.cone = malloc(sizeof(t_cone));
	if (obj->shape.plane == NULL
		&& obj->shape.sphere == NULL
		&& obj->shape.cyl == NULL
		&& obj->shape.cone == NULL)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	new_obj(t_scene *scene, int type)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (FAILURE);
	obj->type = type;
	obj->full_render_image = malloc(sizeof(t_image));
	obj->stub_render_image = malloc(sizeof(t_image));
	if (!obj->full_render_image || !obj->stub_render_image)
		return (new_obj_error(obj));
	if (malloc_object(obj, type) == FAILURE)
		return (new_obj_error(obj));
	(scene->nb_obj)++;
	new_obj_2(obj, scene);
	return (SUCCESS);
}

int	new_lux(t_scene *scene, int type)
{
	t_lux	*lux;

	lux = malloc(sizeof(t_lux));
	if (lux == NULL)
		return (FAILURE);
	lux->type = type;
	lux->src.amb = NULL;
	lux->src.spot = NULL;
	lux->src.dir = NULL;
	if (type == AMBIENT)
		lux->src.amb = malloc(sizeof(t_a_light));
	else if (type == SPOT)
		lux->src.spot = malloc(sizeof(t_s_light));
	else if (type == DIRECTIONAL)
		lux->src.dir = malloc(sizeof(t_d_light));
	if (!lux->src.amb && !lux->src.spot && !lux->src.dir)
	{
		free(lux);
		return (FAILURE);
	}
	lux->next = scene->lux;
	scene->lux = lux;
	return (SUCCESS);
}
