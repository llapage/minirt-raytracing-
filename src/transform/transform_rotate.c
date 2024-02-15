/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:57:10 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:46:11 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vector	rotate_x(t_vector src_v, float amplitude)
{
	float		m[3][3];
	float		rad;
	t_vector	dest_v;

	rad = amplitude * (M_PI / 180);
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cos(rad);
	m[1][2] = -sin(rad);
	m[2][0] = 0;
	m[2][1] = sin(rad);
	m[2][2] = cos(rad);
	dest_v = multiply_matrix(src_v, m);
	return (dest_v);
}

t_vector	rotate_y(t_vector src_v, float amplitude)
{
	float		m[3][3];
	float		rad;
	t_vector	dest_v;

	rad = amplitude * (M_PI / 180);
	m[0][0] = cos(rad);
	m[0][1] = 0;
	m[0][2] = sin(rad);
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = -sin(rad);
	m[2][1] = 0;
	m[2][2] = cos(rad);
	dest_v = multiply_matrix(src_v, m);
	return (dest_v);
}

t_vector	rotate_z(t_vector src_v, float amplitude)
{
	float		m[3][3];
	float		rad;
	t_vector	dest_v;

	rad = amplitude * (M_PI / 180);
	m[0][0] = cos(rad);
	m[0][1] = -sin(rad);
	m[0][2] = 0;
	m[1][0] = sin(rad);
	m[1][1] = cos(rad);
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	dest_v = multiply_matrix(src_v, m);
	return (dest_v);
}
