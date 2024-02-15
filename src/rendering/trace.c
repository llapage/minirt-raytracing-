/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:37:51 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_hit	*set_color(t_hit *hit, t_ray ray, t_data *dt, int depth);
static t_hit	*do_set_color(t_hit *hit, t_data *dt, int depth);
static t_hit	*depth_trace(t_hit *hit, t_data *dt, int depth);
static float	color_mix_ratio(t_hit *hit, int depth);

t_hit	*trace(t_ray ray, t_data *dt, int depth)
{
	t_hit	*hit;

	hit = probe(ray, dt);
	if (intersects_an_object(hit))
		hit = set_color(hit, ray, dt, depth);
	return (hit);
}

static t_hit	*set_color(t_hit *hit, t_ray ray, t_data *dt, int depth)
{
	set_hit_normal(hit, ray, dt);
	hit = do_set_color(hit, dt, depth);
	return (hit);
}

static t_hit	*do_set_color(t_hit *hit, t_data *dt, int depth)
{
	hit->color = color_and_light(hit, dt);
	if (depth)
		hit = depth_trace(hit, dt, depth);
	return (hit);
}

static t_hit	*depth_trace(t_hit *hit, t_data *dt, int depth)
{
	t_hit	*hit_copy;
	t_hit	*depth_hit;
	float	mix_ratio;
	t_ray	depth_ray;

	mix_ratio = color_mix_ratio(hit, depth);
	hit_copy = malloc(sizeof(t_hit));
	if (!hit_copy)
		exit_error("Malloc fail\n", dt);
	*hit_copy = *hit;
	depth_ray = hit->refl;
	depth_ray.type = SECONDARY_RAY;
	depth_hit = trace(depth_ray, dt, depth - 1);
	if (intersects_an_object(depth_hit))
		hit_copy->color = col_mix(hit_copy->color, depth_hit->color, mix_ratio);
	*hit = *hit_copy;
	free(hit_copy);
	return (hit);
}

static float	color_mix_ratio(t_hit *hit, int depth)
{
	float	depth_factor;
	float	refness_factor;
	float	mix_ratio;

	depth_factor = ((float)depth / (float)DEPTH_RAYS);
	refness_factor = ((float)hit->obj->refness / 1000.0);
	mix_ratio = 1 - (depth_factor * refness_factor);
	return (mix_ratio);
}
