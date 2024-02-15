/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:21:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:43:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_sphere *sphere);
static void	set_coefficients(t_quadratic *qd, t_ray ray, t_sphere *sphere);

float	intersect_sphere(t_ray ray, t_sphere *sphere, t_range visib)
{
	t_quadratic	qd;

	if (is_primary_ray(ray) == FALSE)
		set_new_coefficients(&qd, ray, sphere);
	else
		set_coefficients(&qd, ray, sphere);
	return (nearest_solution(&qd, visib));
}

static void	set_new_coefficients(t_quadratic *qd, t_ray ray, t_sphere *sphere)
{
	t_vector	cro;

	cro = vec_between(sphere->ctr, ray.ori);
	qd->a = 1;
	qd->half_b = dot_prod(ray.unit, cro);
	qd->c = vec_sqlen(cro) - sphere->radius_sqrd;
}

static void	set_coefficients(t_quadratic *qd, t_ray ray, t_sphere *sphere)
{
	qd->a = 1;
	qd->half_b = dot_prod(ray.unit, sphere->ctr_cam_vec);
	qd->c = sphere->trinomial_c;
}
