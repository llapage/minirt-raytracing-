/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:16 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:35:13 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

struct s_vec	unit_interval_pix_l(float x, float y)
{
	t_vertex	pixel;

	pixel.x = x;
	pixel.y = y;
	return (pixel);
}

int	is_zero(float f)
{
	if (f < -FLT_MIN || f > FLT_MIN)
		return (0);
	return (1);
}

int	vec_is_y_axis(t_vector vec)
{
	if (is_zero(vec.x) && is_zero(vec.z) && (vec.y == 1.0 || vec.y == -1.0))
		return (1);
	return (0);
}

float	vtx_distance(t_vertex a, t_vertex b)
{
	return (vec_magnitude(vec_between(a, b)));
}
