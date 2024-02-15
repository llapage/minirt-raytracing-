/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/25 00:39:45 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_vertex	sphere_surface_map(t_hit *hit);
static t_vertex	plane_surface_map(t_hit *hit);
static t_vertex	cyl_surface_map(t_hit *hit);

t_vertex	surface_map(t_hit *hit)
{
	t_unit_interval_pixel	uip;

	if (hit->obj->type == SPHERE)
		uip = sphere_surface_map(hit);
	else if (hit->obj->type == PLANE)
		uip = plane_surface_map(hit);
	else if (hit->obj->type == CYL)
		uip = cyl_surface_map(hit);
	else
		uip = new_vertex(0, 0, 0);
	return (uip);
}

static t_vertex	sphere_surface_map(t_hit *hit)
{
	float		azimuth;
	float		polar;
	t_vector	ctr_hit_unit;

	ctr_hit_unit = vec_unit(hit->ctr_hit_vec);
	azimuth = atan2(ctr_hit_unit.x, ctr_hit_unit.z);
	polar = acos(ctr_hit_unit.y);
	return (unit_interval_pix_l((azimuth / (2.0 * M_PI) + 0.5), polar / M_PI));
}

static t_vertex	plane_surface_map(t_hit *hit)
{
	return (unit_interval_pix_l(fmod(hit->vtx.x / 100.0, 1),
			fmod(hit->vtx.z / 100.0, 1)));
}

static t_vertex	cyl_surface_map(t_hit *hit)
{
	float		azimuth;
	t_vector	ctr_hit_unit;

	ctr_hit_unit = vec_unit(hit->ctr_hit_vec);
	azimuth = atan2(ctr_hit_unit.x, ctr_hit_unit.z);
	return (unit_interval_pix_l(1 - (azimuth / (2.0 * M_PI) + 0.5), 
			fmod(hit->vtx.y, 1)));
}
