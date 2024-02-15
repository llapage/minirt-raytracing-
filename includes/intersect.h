/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 17:15:25 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "defs.h"
# include "vector.h"
# include "scene.h"

enum e_cylinder_intersection_combinations
{
	ONE_INTERSECTION,
	TWO_SIDE_INTERSECTIONS,
	NO_INTERSECTIONS,
	TOP_AND_SIDE_INTERSECTIONS,
	BASE_AND_SIDE_INTERSECTIONS,
	BASE_AND_TOP_INTERSECTIONS
};

enum e_cylinder_intersection_relative_locations
{
	BELOW_BASE_INTERSECTION = 0,
	WITHIN_CAPS_INTERSECTION = 1,
	ABOVE_TOP_INTERSECTION = 2
};

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	half_b;
	float	c;
	float	discriminant;
	float	nb_solutions;
	float	solution_1;
	float	solution_2;
	float	nearest;
	t_range	visible_range;
}	t_quadratic;

typedef struct s_calc
{
	float	ctr_cam_vec_dot_axis_vec;
	float	ray_unit_vec_dot_axis_vec;
	int		intersection_combination;
}	t_calc;

float	intersect(t_ray ray, t_obj *obj, t_range range);
float	intersect_sphere( t_ray ray, t_sphere *sphere, t_range range);
float	intersect_plane(t_ray ray, t_plane *plane, t_range range);
float	intersect_cone(t_ray ray, t_cone *cone, t_range range);
float	intersect_cyl(t_ray ray, t_cyl *cyl, t_range range);

/* ************************************************************************** */
/*                                                                            */
/*    GET utility functions                                                   */
/*                                                                            */
/* ************************************************************************** */
float	nearest_solution(t_quadratic *qd, t_range range);
float	calculate_nearest(t_quadratic *qd, t_range range);
float	nearest_visible(float a, float b, t_range range);
float	nearest_solution_visible(t_quadratic *qd);
int		cylinder_intersection_relative_location(
			float intersection_height, float object_height);
float	one_intersection(t_quadratic *qd);
float	cyl_plane_distance(float ctr_cam_vec_dot_axis_vec,
			float ray_unit_vec_dot_axis_vec);

/* ************************************************************************** */
/*                                                                            */
/*    SET utility functions                                                   */
/*                                                                            */
/* ************************************************************************** */
void	resolve_cyl_intersection_combination(
			t_quadratic *qd, float object_height, t_calc *calc);
void	calculate_discriminant(t_quadratic *qd);
void	calculate_nb_solutions(t_quadratic *qd);
void	calculate_solutions(t_quadratic *qd);
void	discard_invalid_cyl_intersection(float *solution,
			int relative_location);
void	calculate_cyl_nearest(
			t_quadratic *qd, t_ray ray, t_cyl *cyl, t_calc *calc);
void	calculate_cone_nearest(
			t_quadratic *qd, t_ray ray, t_cone *cone, t_calc *calc);

/* ************************************************************************** */
/*                                                                            */
/*    BOOL utility functions                                                  */
/*                                                                            */
/* ************************************************************************** */
int		is_zero(float a);
int		depth_tracing(void);

#endif
