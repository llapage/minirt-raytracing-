/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:20:30 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:43:24 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static float	distance(t_ray ray, t_plane *plane, float denom, t_range visib);
static float	numerator(t_ray ray, t_plane *plane);
static float	calculate_numer(t_ray ray, t_plane *plane);

float	intersect_plane(t_ray ray, t_plane *plane, t_range visib)
{
	float			denom;
	float			dist;

	denom = dot_prod(ray.unit, plane->norm);
	if (is_zero(denom) == TRUE)
		dist = FLT_MAX;
	else
		dist = distance(ray, plane, denom, visib);
	return (dist);
}

static float	distance(t_ray ray, t_plane *plane, float denom, t_range visib)
{
	float			numer;
	float			dist;

	numer = numerator(ray, plane);
	dist = numer / denom;
	if (within_range(dist, visib) == FALSE)
		dist = FLT_MAX;
	return (dist);
}

static float	numerator(t_ray ray, t_plane *plane)
{
	float			numer;

	if (is_primary_ray(ray) == FALSE)
		numer = calculate_numer(ray, plane);
	else
		numer = -plane->ctr_cam_dot_norm;
	return (numer);
}

static float	calculate_numer(t_ray ray, t_plane *plane)
{
	float		numer;
	t_vector	pro;

	pro = vec_between(plane->ctr, ray.ori);
	numer = -dot_prod(pro, plane->norm);
	return (numer);
}
