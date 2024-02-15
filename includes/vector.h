/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:49:35 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:41:53 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>
# include <math.h>
# include "defs.h"

typedef enum e_ray_type
{
	PRIMARY_RAY,
	SECONDARY_RAY,
	SHADOW_RAY
}	t_ray_type;

typedef struct s_intersections
{
	float	t1;
	float	t2;
}	t_intersections;

typedef struct s_range
{
	float	min;
	float	max;
}	t_range;

typedef struct s_vec
{
	float	magnitude;
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef t_vector	t_vertex;
typedef t_vector	t_unit_interval_pixel;

typedef struct s_matrix
{
	float	**data;
	int		columns;
	int		rows;
}	t_matrix;

typedef struct s_ray
{
	t_vector	unit;
	t_vector	vec;
	t_vertex	ori;
	t_vertex	end;
	t_ray_type	type;
	float		len;
}	t_ray;

struct s_vec	unit_interval_pix_l(float x, float y);
t_vertex		new_vertex(float x, float y, float z);
t_vertex		vtx_translate(t_vertex a, t_vector b);
t_vector		new_vector(float x, float y, float z);
t_vector		vec_subtract(t_vector a, t_vector b);
t_vector		vec_between(t_vertex a, t_vertex b);
t_vector		vec_multiply(t_vector a, float b);
t_vector		vec_cross(t_vector a, t_vector b);
t_vector		vec_add(t_vector a, t_vector b);
t_vector		vec_divide(t_vector a, float b);
t_vector		vec_perp(t_vector a);
t_vector		vec_unit(t_vector a);
t_vector		vec_inv(t_vector a);
t_range			new_range(float min, float max);
t_ray			vtx_cross_prod(t_vertex common, t_vertex a, t_vertex b);
t_ray			ray_incident(t_ray left, t_ray middle);
t_ray			new_ray(t_vertex orig, t_vector vec);
t_ray			ray_between(t_vertex a, t_vertex b);
t_ray			cross_prod(t_ray a, t_ray b);
float			perp_dist(t_vertex from, t_vertex line_a, t_vertex line_b);
float			vtx_distance(t_vertex a, t_vertex b);
float			dot_prod(t_vector a, t_vector b);
float			vec_sqlen(t_vector a);
float			vec_magnitude(t_vector vector);
void			print_vector(char *desc, t_vector vec);
void			print_vertex(char *desc, t_vertex vtx);
int				within_range(float a, t_range range);
int				vec_is_y_axis(t_vector vec);
int				is_primary_ray(t_ray ray);
#endif
