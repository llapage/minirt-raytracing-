/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:52:06 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 21:54:50 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

float	nearest_solution(t_quadratic *qd, t_range visible_range)
{
	float	nearest;

	calculate_discriminant(qd);
	calculate_nb_solutions(qd);
	if (qd->nb_solutions == NONE)
		nearest = FLT_MAX;
	else if (qd->nb_solutions == 1)
		nearest = -qd->half_b / qd->a;
	else
		nearest = calculate_nearest(qd, visible_range);
	return (nearest);
}

float	calculate_nearest(t_quadratic *qd, t_range visible_range)
{
	float	nearest;

	calculate_solutions(qd);
	qd->visible_range = visible_range;
	nearest = nearest_solution_visible(qd);
	return (nearest);
}

float	nearest_visible(float a, float b, t_range visib)
{
	float	nearest;

	if (within_range(a, visib) == TRUE)
	{
		if (within_range(b, visib) == TRUE)
			nearest = fmin(a, b);
		else 
			nearest = a;
	}
	else if (within_range(b, visib) == TRUE)
		nearest = b;
	else
		nearest = FLT_MAX;
	return (nearest);
}

float	nearest_solution_visible(t_quadratic *qd)
{
	return (nearest_visible(qd->solution_1, qd->solution_2, qd->visible_range));
}

int	cylinder_intersection_relative_location(float intersection_height, 
		float object_height)
{
	int	location;

	if (intersection_height > object_height)
		location = ABOVE_TOP_INTERSECTION;
	else if (intersection_height >= FLT_MIN)
		location = WITHIN_CAPS_INTERSECTION;
	else
		location = BELOW_BASE_INTERSECTION;
	return (location);
}
