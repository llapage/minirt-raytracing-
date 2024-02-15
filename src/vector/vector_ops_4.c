/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:16 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:59:35 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_ray	ray_incident(t_ray left, t_ray middle)
{
	t_ray	right;

	right = new_ray(left.ori,
			vec_subtract(vec_multiply(vec_multiply(middle.unit,
						dot_prod(middle.unit, left.vec)), 2), left.vec));
	return (right);
}

t_vector	vec_cross(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.y * b.z - b.y * a.z;
	c.y = a.z * b.x - b.z * a.x;
	c.z = a.x * b.y - b.x * a.y;
	return (c);
}

t_ray	cross_prod(t_ray a, t_ray b)
{
	t_vertex	end;

	end.x = a.vec.y * b.vec.z - a.vec.z * b.vec.y;
	end.y = a.vec.z * b.vec.x - a.vec.x * b.vec.z;
	end.z = a.vec.x * b.vec.y - a.vec.y * b.vec.x;
	return (ray_between(a.ori, end));
}

t_ray	vtx_cross_prod(t_vertex common, t_vertex a, t_vertex b)
{
	t_ray		r_a;
	t_ray		r_b;

	r_a = ray_between(common, a);
	r_b = ray_between(common, b);
	return (cross_prod(r_a, r_b));
}
