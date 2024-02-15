/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:19:20 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:09:14 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static float	top_and_side_intersections(t_quadratic *qd, t_ray ray, 
					t_cone *cone, t_calc *calc);
static float	cone_top_distance(t_ray ray, t_cone *cone, t_calc *calc);

void	calculate_cone_nearest(
		t_quadratic *qd, t_ray ray, t_cone *cone, t_calc *calc)
{
	float	nearest;

	if (calc->intersection_combination == ONE_INTERSECTION)
		nearest = one_intersection(qd);
	else if (calc->intersection_combination == TWO_SIDE_INTERSECTIONS)
		nearest = nearest_solution_visible(qd);
	else if (calc->intersection_combination == TOP_AND_SIDE_INTERSECTIONS)
		nearest = top_and_side_intersections(qd, ray, cone, calc);
	else if (calc->intersection_combination == NO_INTERSECTIONS)
		nearest = FLT_MAX;
	else
		nearest = FLT_MAX;
	qd->nearest = nearest;
}

static float	top_and_side_intersections(t_quadratic *qd, t_ray ray, 
			t_cone *cone, t_calc *calc)
{
	float	to_top_distance;
	float	to_side_distance;
	float	nearest;

	to_top_distance = cone_top_distance(ray, cone, calc);
	to_side_distance = nearest_solution_visible(qd);
	nearest = nearest_visible(to_top_distance, to_side_distance, 
			qd->visible_range);
	return (nearest);
}

static float	cone_top_distance(t_ray ray, t_cone *cone, t_calc *calc)
{
	t_vector	cor;
	float		ctr_cam_vec_dot_axis_vec;
	float		distance;

	if (depth_tracing())
	{
		cor = vec_between(cone->top.ctr, ray.ori);
		ctr_cam_vec_dot_axis_vec = dot_prod(cor, cone->axis);
	}
	else
		ctr_cam_vec_dot_axis_vec = cone->top.ctr_cam_dot_norm;
	distance = cyl_plane_distance(ctr_cam_vec_dot_axis_vec, 
			calc->ray_unit_vec_dot_axis_vec);
	return (distance);
}
