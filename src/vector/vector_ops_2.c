/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:07:44 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/15 09:17:58 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_ray	new_ray(t_vertex orig, t_vector vec)
{
	t_ray	ray;

	ray.ori = orig;
	ray.end = vtx_translate(orig, vec);
	ray.vec = vec;
	ray.len = vec_magnitude(ray.vec);
	ray.unit = vec_unit(ray.vec);
	return (ray);
}

t_vertex	new_vertex(float x, float y, float z)
{
	t_vertex	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vector	vec_between(t_vertex a, t_vertex b)
{
	t_vector	res;

	res.x = b.x - a.x;
	res.y = b.y - a.y;
	res.z = b.z - a.z;
	res.magnitude = vec_magnitude(res);
	return (res);
}

t_ray	ray_between(t_vertex a, t_vertex b)
{
	return (new_ray(a, vec_between(a, b)));
}

t_vertex	vtx_translate(t_vertex a, t_vector b)
{
	t_vertex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}
