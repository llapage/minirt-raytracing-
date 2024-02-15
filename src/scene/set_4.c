/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 16:22:04 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	range_wrap_object_commons(t_obj *object)
{
	uint_wrap(&object->color.red, 0, 255);
	uint_wrap(&object->color.green, 0, 255);
	uint_wrap(&object->color.blue, 0, 255);
	uint_wrap(&object->gloss, 0, 1000);
	uint_wrap(&object->refness, 0, 1000);
}

void	range_wrap_plane(t_plane *plane)
{
	float_wrap(&plane->norm.x, -1.0, 1.0);
	float_wrap(&plane->norm.y, -1.0, 1.0);
	float_wrap(&plane->norm.z, -1.0, 1.0);
}

void	range_wrap_sphere(t_sphere *sphere)
{
	float_wrap(&sphere->diameter, FLT_MIN, FLT_MAX);
}

void	range_wrap_cone(t_cone *cone)
{
	float_wrap(&cone->axis.x, -1.0, 1.0);
	float_wrap(&cone->axis.y, -1.0, 1.0);
	float_wrap(&cone->axis.z, -1.0, 1.0);
	float_wrap(&cone->diameter, FLT_MIN, FLT_MAX);
	float_wrap(&cone->height, FLT_MIN, FLT_MAX);
}

void	range_wrap_cyl(t_cyl *cyl)
{
	float_wrap(&cyl->axis.x, -1.0, 1.0);
	float_wrap(&cyl->axis.y, -1.0, 1.0);
	float_wrap(&cyl->axis.z, -1.0, 1.0);
	float_wrap(&cyl->diameter, FLT_MIN, FLT_MAX);
	float_wrap(&cyl->height, FLT_MIN, FLT_MAX);
}
