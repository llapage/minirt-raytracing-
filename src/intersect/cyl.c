/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:19:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:42:20 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_cyl *cyl, 
				t_calc *calc);
static void	set_coefficients(t_quadratic *qd, t_ray ray, t_cyl *cyl, 
				t_calc *calc);

float	intersect_cyl(t_ray ray, t_cyl *cyl, t_range visib)
{
	t_quadratic	qd;
	t_calc		calc;

	calc.ray_unit_vec_dot_axis_vec = dot_prod(ray.unit, cyl->axis);
	qd.visible_range = visib;
	if (is_primary_ray(ray) == FALSE)
		set_new_coefficients(&qd, ray, cyl, &calc);
	else
		set_coefficients(&qd, ray, cyl, &calc);
	calculate_discriminant(&qd);
	resolve_cyl_intersection_combination(&qd, cyl->height, &calc);
	calculate_cyl_nearest(&qd, ray, cyl, &calc);
	return (qd.nearest);
}

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_cyl *cyl, 
			t_calc *calc)
{
	t_vector	cor;

	cor = vec_between(cyl->base.ctr, ray.ori);
	calc->ctr_cam_vec_dot_axis_vec = dot_prod(cor, cyl->axis);
	qd->a = 1
		- pow(calc->ray_unit_vec_dot_axis_vec, 2);
	qd->half_b = ((dot_prod(ray.unit, cor))
			- calc->ray_unit_vec_dot_axis_vec
			* calc->ctr_cam_vec_dot_axis_vec);
	qd->c = vec_sqlen(cor)
		- pow(calc->ctr_cam_vec_dot_axis_vec, 2)
		- cyl->radius_sqrd;
}

static void	set_coefficients(t_quadratic *qd, t_ray ray, t_cyl *cyl, 
			t_calc *calc)
{
	calc->ctr_cam_vec_dot_axis_vec = cyl->base.ctr_cam_dot_norm;
	qd->a = 1
		- pow(calc->ray_unit_vec_dot_axis_vec, 2);
	qd->half_b = ((dot_prod(ray.unit, cyl->base.ctr_cam_vec))
			- calc->ray_unit_vec_dot_axis_vec
			* calc->ctr_cam_vec_dot_axis_vec);
	qd->c = cyl->base.trinomial_c;
}
