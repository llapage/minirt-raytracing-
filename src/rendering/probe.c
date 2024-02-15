/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 15:43:43 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_hit	*find_nearest_intersection(t_ray ray, t_hit *hit, t_data *dt);
static t_hit	*update_nearest_intersection(
					t_ray ray, t_obj *obj, t_hit *hit, t_data *dt);
static t_hit	*set_nearest_intersection(
					t_obj *obj, float objects_distance, t_hit *hit);

t_hit	*probe(t_ray ray, t_data *dt)
{
	t_hit	*hit;

	hit = &dt->new_hit;
	initialise_hit(hit, dt);
	hit = find_nearest_intersection(ray, hit, dt);
	return (hit);
}

static t_hit	*find_nearest_intersection(t_ray ray, t_hit *hit, t_data *dt)
{
	t_obj	*obj;

	obj = first_object(dt);
	while (obj)
	{
		hit = update_nearest_intersection(ray, obj, hit, dt);
		next_object(&obj);
	}
	return (hit);
}

static t_hit	*update_nearest_intersection(
			t_ray ray, t_obj *obj, t_hit *hit, t_data *dt)
{
	float	objects_distance;

	dt->ray_count++;
	objects_distance = intersect(ray, obj, dt->visib);
	set_nearest_intersection(obj, objects_distance, hit);
	mark_object_as_hit_or_not_hit(obj, objects_distance, dt);
	return (hit);
}

static t_hit	*set_nearest_intersection(
			t_obj *obj, float objects_distance, t_hit *hit)
{
	if (new_nearest_object(objects_distance, hit))
		update_nearest(obj, objects_distance, hit);
	return (hit);
}
