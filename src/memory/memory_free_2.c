/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:06:25 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:03:40 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void	free_lux(t_scene *scene)
{
	t_lux	*lux;

	lux = scene->lux;
	while (lux)
	{
		if (lux->type == AMBIENT)
			free(lux->src.amb);
		else if (lux->type == SPOT)
			free(lux->src.spot);
		else if (lux->type == DIRECTIONAL)
			free(lux->src.dir);
		lux = scene->lux->next;
		free(scene->lux);
		scene->lux = lux;
	}
}

static void	free_obj_2(t_obj **obj, t_data *dt)
{
	free((*obj)->full_render_image);
	free((*obj)->stub_render_image);
	*obj = dt->scene->obj->next;
	free(dt->scene->obj);
	dt->scene->obj = *obj;
}

void	free_obj(t_data *dt)
{
	t_obj	*obj;

	obj = dt->scene->obj;
	while (obj)
	{
		if (obj->type == PLANE)
			free(obj->shape.plane);
		else if (obj->type == SPHERE)
			free(obj->shape.sphere);
		else if (obj->type == CYL)
			free(obj->shape.cyl);
		else if (obj->type == CONE)
			free(obj->shape.cone);
		if (dt->mlx)
		{
			mlx_destroy_image(dt->mlx, obj->full_render_image->ptr);
			mlx_destroy_image(dt->mlx, obj->stub_render_image->ptr);
		}
		free_obj_2(&obj, dt);
	}
}
