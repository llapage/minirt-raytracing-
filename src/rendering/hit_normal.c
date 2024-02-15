/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 11:05:54 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_ray	normal_map(t_hit *hit, t_vector smooth_normal, t_data *dt);
static t_ray	get_normal_map(t_hit *hit, char *normal_map,
					t_vector smooth_normal, t_data *dt);
static t_vector	get_surface_vector(t_hit *hit, char *normal_map, t_data *dt);

void	set_hit_normal(t_hit *hit, t_ray ray, t_data *dt)
{
	int			surface;
	t_ray		normal_ray;
	t_vector	smooth_normal;

	surface = hit->obj->surface;
	hit->vtx = vtx_translate(ray.ori, vec_multiply(ray.unit, hit->dist));
	smooth_normal = smooth_intersection_normal(hit);
	if (surface == SMOOTH_SURFACE)
		normal_ray = new_ray(hit->vtx, smooth_normal);
	else if (surface == PERLIN_SURFACE)
		normal_ray = new_ray(hit->vtx, smooth_normal);
	else
		normal_ray = normal_map(hit, smooth_normal, dt);
	hit->norm = normal_ray;
	hit->ctr_hit_vec = vec_between(*hit->obj->ctr, hit->vtx);
	hit->src = ray_between(hit->vtx, ray.ori);
	hit->refl = ray_incident(hit->src, hit->norm);
}

static t_ray	normal_map(t_hit *hit, t_vector smooth_normal, t_data *dt)
{
	int		surface;
	t_ray	normal;

	surface = hit->obj->surface;
	if (surface == EARTH_SURFACE)
		normal = get_normal_map(hit, "earth_nm", smooth_normal, dt);
	else if (surface == MOON_SURFACE)
		normal = get_normal_map(hit, "moon_nm", smooth_normal, dt);
	else
		normal = new_ray(new_vertex(0, 0, 0), new_vector(0, 0, 0));
	return (normal);
}

static t_ray	get_normal_map(t_hit *hit, char *normal_map, 
			t_vector smooth_normal, t_data *dt)
{
	t_vector	surface_vector;
	t_vector	normalised_vector;

	surface_vector = get_surface_vector(hit, normal_map, dt);
	normalised_vector = vec_add(smooth_normal, surface_vector);
	normalised_vector = vec_unit(normalised_vector);
	return (new_ray(hit->vtx, normalised_vector));
}

static t_vector	get_surface_vector(t_hit *hit, char *normal_map, t_data *dt)
{
	t_vector	surface_vector;
	t_color		normal;
	float		x;
	float		y;
	float		z;

	normal = color_at(surface_map(hit), get_graphic(dt, normal_map));
	y = fmin(1, (normal.red - 127.0) / 127.0);
	x = fmin(1, (normal.green - 127.0) / 127.0);
	z = fmin(1, (normal.blue - 127.0) / 127.0);
	surface_vector = new_vector(x, y, z);
	return (surface_vector);
}
