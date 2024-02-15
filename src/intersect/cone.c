/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:19:20 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:13:42 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_cone *cone,
				t_calc *calc);
static void	set_coefficients(t_quadratic *qd, t_ray ray, t_cone *cone,
				t_calc *calc);

float	intersect_cone(t_ray ray, t_cone *cone, t_range visib)
{
	t_quadratic	qd;
	t_calc		calc;

	calc.ray_unit_vec_dot_axis_vec = dot_prod(ray.unit, cone->axis);
	qd.visible_range = visib;
	if (is_primary_ray(ray) == FALSE)
		set_new_coefficients(&qd, ray, cone, &calc);
	else
		set_coefficients(&qd, ray, cone, &calc);
	calculate_discriminant(&qd);
	resolve_cyl_intersection_combination(&qd, cone->height, &calc);
	calculate_cone_nearest(&qd, ray, cone, &calc);
	return (qd.nearest);
}

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_cone *cone, 
		t_calc *calc)
{
	t_vector	cor;

	cor = vec_between(cone->ctr, ray.ori);
	calc->ctr_cam_vec_dot_axis_vec = dot_prod(cor, cone->axis);
	qd->a = 1 
		- cone->ctr_half_angle_tan_sqrd_plus_one
		* pow(calc->ray_unit_vec_dot_axis_vec, 2); 
	qd->half_b = ((dot_prod(ray.unit, cor))
			- cone->ctr_half_angle_tan_sqrd_plus_one
			* calc->ray_unit_vec_dot_axis_vec
			* calc->ctr_cam_vec_dot_axis_vec);
	qd->c = vec_sqlen(cor)
		- cone->ctr_half_angle_tan_sqrd_plus_one
		* pow(calc->ctr_cam_vec_dot_axis_vec, 2);
}

static void	set_coefficients(t_quadratic *qd, t_ray ray, t_cone *cone, 
			t_calc *calc)
{
	calc->ctr_cam_vec_dot_axis_vec = cone->ctr_cam_dot_norm;
	qd->a = 1 
		- cone->ctr_half_angle_tan_sqrd_plus_one
		* pow(calc->ray_unit_vec_dot_axis_vec, 2); 
	qd->half_b = ((dot_prod(ray.unit, cone->ctr_cam_vec))
			- cone->ctr_half_angle_tan_sqrd_plus_one
			* calc->ray_unit_vec_dot_axis_vec
			* calc->ctr_cam_vec_dot_axis_vec);
	qd->c = cone->trinomial_c;
}
