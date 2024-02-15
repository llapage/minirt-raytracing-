/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:52:06 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 13:36:23 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

void	calculate_discriminant(t_quadratic *qd)
{
	qd->discriminant = pow(qd->half_b, 2) - qd->a * qd->c;
}

void	calculate_nb_solutions(t_quadratic *qd)
{
	if (is_zero(qd->discriminant))
		qd->nb_solutions = 1;
	else if (qd->discriminant > 0)
		qd->nb_solutions = 2;
	else
		qd->nb_solutions = 0;
}

void	calculate_solutions(t_quadratic *qd)
{
	float	sqrt_discriminant;

	sqrt_discriminant = sqrt(qd->discriminant);
	qd->solution_1 = (-qd->half_b + sqrt_discriminant) / qd->a;
	qd->solution_2 = (-qd->half_b - sqrt_discriminant) / qd->a;
}

void	discard_invalid_cyl_intersection(float	*solution, 
		int relative_location)
{
	if (relative_location != WITHIN_CAPS_INTERSECTION)
		*solution = FLT_MAX;
}
