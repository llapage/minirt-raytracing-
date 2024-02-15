/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:15:56 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

float	strenght_of_reflection_back_to_the_light(t_hit *hit, t_ray light_ray)
{
	return (dot_prod(hit->norm.unit, light_ray.vec));
}

float	strenght_of_reflection_toward_the_viewer(t_hit *hit, t_ray light_ray)
{
	t_ray	reflection;

	reflection = ray_incident(light_ray, hit->norm);
	return (dot_prod(reflection.vec, hit->src.vec));
}

t_ray	ray_from_focal_point_to_super_viewport_point(t_data *dt)
{
	t_ray	ray;

	ray = ray_between(dt->vp->cam, next_sub_px(dt));
	ray.type = PRIMARY_RAY;
	return (ray);
}

int	nb_depth_rays(t_data *dt)
{
	int	nb;

	if (is_set(dt->reflections_switch))
		nb = DEPTH_RAYS;
	else
		nb = 0;
	return (nb);
}
