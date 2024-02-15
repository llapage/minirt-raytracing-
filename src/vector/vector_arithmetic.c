/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:51:25 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/15 09:40:29 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vector	vec_add(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.magnitude = vec_magnitude(res);
	return (res);
}

t_vector	vec_subtract(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.magnitude = vec_magnitude(res);
	return (res);
}

t_vector	vec_divide(t_vector a, float b)
{
	t_vector	res;

	res.x = 0;
	res.y = 0;
	res.z = 0;
	if (!b)
		return (res);
	res.x = a.x / b;
	res.y = a.y / b;
	res.z = a.z / b;
	res.magnitude = vec_magnitude(res);
	return (res);
}

t_vector	vec_multiply(t_vector a, float b)
{
	t_vector	res;

	res.x = a.x * b;
	res.y = a.y * b;
	res.z = a.z * b;
	res.magnitude = vec_magnitude(res);
	return (res);
}
