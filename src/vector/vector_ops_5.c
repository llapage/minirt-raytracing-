/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:16 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:45:06 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

float	perp_dist(t_vertex from, t_vertex line_a, t_vertex line_b)
{
	t_ray	line;
	t_ray	cross;
	t_ray	r_cross;

	line = ray_between(line_a, line_b);
	cross = vtx_cross_prod(line_a, from, line_b);
	r_cross = ray_between(new_vertex(0, 0, 0), cross.end);
	return (r_cross.len / line.len);
}

t_vector	vec_perp(t_vector a)
{
	t_vector	res;

	res.x = 0;
	res.z = 1;
	res.y = -a.y;
	if (perp_dist(new_vertex(res.x, res.y, res.z), 
			new_vertex(0, 0, 0), new_vertex(a.x, a.y, a.z)))
		return (res);
	res.z = 0;
	res.y = 1;
	res.x = -a.z;
	if (perp_dist(new_vertex(res.x, res.y, res.z), 
			new_vertex(0, 0, 0), new_vertex(a.x, a.y, a.z)))
		return (res);
	res.y = 0;
	res.x = 1;
	res.x = -a.z;
	return (res);
}

float	vec_sqlen(t_vector a)
{
	return (dot_prod(a, a));
}

int	is_primary_ray(t_ray ray)
{
	if (ray.type == PRIMARY_RAY)
		return (TRUE);
	else
		return (FALSE);
}
