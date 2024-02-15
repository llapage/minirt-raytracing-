/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:52:06 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:06:53 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

float	cyl_plane_distance(float ctr_cam_vec_dot_axis_vec,
		float ray_unit_vec_dot_axis_vec)
{
	float	distance;

	if (is_zero(ray_unit_vec_dot_axis_vec))
		distance = FLT_MAX;
	else
		distance = -ctr_cam_vec_dot_axis_vec / ray_unit_vec_dot_axis_vec;
	return (distance);
}

float	one_intersection(t_quadratic *qd)
{
	float	nearest;

	nearest = -qd->half_b / qd->a;
	if (within_range(nearest, qd->visible_range) == FALSE)
		nearest = FLT_MAX;
	return (nearest);
}
