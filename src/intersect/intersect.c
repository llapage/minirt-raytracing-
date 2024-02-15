/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:18:28 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:25:41 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

float	intersect(t_ray ray, t_obj *obj, t_range visib)
{
	float	nearest;

	if (obj->type == SPHERE)
		nearest = intersect_sphere(ray, obj->shape.sphere, visib);
	else if (obj->type == PLANE)
		nearest = intersect_plane(ray, obj->shape.plane, visib);
	else if (obj->type == CYL)
		nearest = intersect_cyl(ray, obj->shape.cyl, visib);
	else if (obj->type == CONE)
		nearest = intersect_cone(ray, obj->shape.cone, visib);
	else
		nearest = FLT_MAX;
	return (nearest);
}
