/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 00:17:12 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_hit	*simple_trace(t_data *dt)
{
	t_ray	ray;
	t_hit	*hit;

	ray = ray_from_focal_point_to_viewport_point(dt);
	hit = probe(ray, dt);
	if (intersects_an_object(hit))
	{
		save_intersection_point_and_norm(hit, ray);
		link_object_color(hit);
	}
	fill_hit_subsample_gaps(hit, dt);
	return (hit);
}
