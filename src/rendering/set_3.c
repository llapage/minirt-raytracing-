/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 19:56:04 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	update_nearest(t_obj *obj, float objects_distance, t_hit *hit)
{
	hit->obj = obj;
	hit->dist = objects_distance;
}

void	mark_object_as_hit_or_not_hit(
		t_obj *obj, float objects_distance, t_data *dt)
{
	if (objects_distance < FLT_MAX)
		obj->hit[dt->px.y][dt->px.x] = 1;
	else
		obj->hit[dt->px.y][dt->px.x] = 0;
}

void	save_intersection_point_and_norm(t_hit *hit, t_ray ray)
{
	hit->vtx = vtx_translate(ray.ori, vec_multiply(ray.unit, hit->dist));
	hit->ctr_hit_vec = vec_between(*hit->obj->ctr, hit->vtx);
}
