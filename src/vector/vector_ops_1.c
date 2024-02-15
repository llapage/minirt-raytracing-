/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:01:30 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/21 01:21:20 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.magnitude = vec_magnitude(res);
	return (res);
}

t_vector	vec_unit(t_vector a)
{
	t_vector	res;
	float		magnitude;

	magnitude = vec_magnitude(a);
	res = vec_divide(a, magnitude);
	return (res);
}

t_vector	vec_inv(t_vector a)
{
	t_vector	res;

	res.x = -a.x;
	res.y = -a.y;
	res.z = -a.z;
	return (res);
}

float	dot_prod(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	vec_magnitude(t_vector a)
{
	return (sqrt(dot_prod(a, a)));
}
