/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_calculation_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:19:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:14:54 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static int		calculate_intersection_combination(t_quadratic *qd, 
					float object_height, t_calc *calc);
static int		logical_result_combination(int location_1, int location_2);

void	resolve_cyl_intersection_combination(t_quadratic *qd, 
		float object_height, t_calc *calc)
{
	int	intersection_combination;

	if (is_zero(qd->discriminant) == TRUE)
		intersection_combination = ONE_INTERSECTION;
	else if (qd->discriminant > 0)
		intersection_combination = calculate_intersection_combination(
				qd, object_height, calc);
	else
		intersection_combination = NO_INTERSECTIONS;
	calc->intersection_combination = intersection_combination;
}

static int	calculate_intersection_combination(t_quadratic *qd, 
			float object_height, t_calc *calc)
{
	float	relative_height_1;
	float	relative_height_2;
	int		location_1;
	int		location_2;
	int		intersection_combination;

	calculate_solutions(qd);
	relative_height_1 = 
		calc->ctr_cam_vec_dot_axis_vec 
		+ calc->ray_unit_vec_dot_axis_vec 
		* qd->solution_1;
	relative_height_2 = 
		calc->ctr_cam_vec_dot_axis_vec 
		+ calc->ray_unit_vec_dot_axis_vec 
		* qd->solution_2;
	location_1 = cylinder_intersection_relative_location(
			relative_height_1, object_height);
	location_2 = cylinder_intersection_relative_location(
			relative_height_2, object_height);
	discard_invalid_cyl_intersection(&qd->solution_1, location_1);
	discard_invalid_cyl_intersection(&qd->solution_2, location_2);
	intersection_combination = logical_result_combination(
			location_1, location_2);
	return (intersection_combination);
}

static int	logical_result_combination(int location_1, int location_2)
{
	int	intersection_combination;

	if ((location_1 ^ location_2) == 0)
	{
		if ((location_1 | location_2) == 1)
			intersection_combination = TWO_SIDE_INTERSECTIONS;
		else
			intersection_combination = NO_INTERSECTIONS;
	}
	else if ((location_1 ^ location_2) == 3)
		intersection_combination = TOP_AND_SIDE_INTERSECTIONS;
	else
	{
		if ((location_1 ^ location_2) == 1)
			intersection_combination = BASE_AND_SIDE_INTERSECTIONS;
		else
			intersection_combination = BASE_AND_TOP_INTERSECTIONS;
	}
	return (intersection_combination);
}
