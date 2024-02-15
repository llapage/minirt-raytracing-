/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_intersection_normal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 11:07:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_vector	sphere_normal(t_hit *hit);
static t_vector	cyl_normal(t_hit *hit);
static t_vector	plane_normal(t_hit *hit);
static t_vector	cone_normal(t_hit *hit);

t_vector	smooth_intersection_normal(t_hit *hit)
{
	int			type;
	t_vector	normal;

	type = hit->obj->type;
	if (type == SPHERE) 
		normal = sphere_normal(hit);
	else if (type == CYL)
		normal = cyl_normal(hit);
	else if (type == PLANE)
		normal = plane_normal(hit);
	else if (type == CONE)
		normal = cone_normal(hit);
	else
		normal = new_vector(0, 0, 0);
	return (normal);
}

static t_vector	sphere_normal(t_hit *hit)
{
	t_vector	normal;

	hit->ctr_hit_vec = vec_between(*hit->obj->ctr, hit->vtx);
	normal = vec_unit(hit->ctr_hit_vec);
	return (normal);
}

static t_vector	cyl_normal(t_hit *hit)
{
	t_cyl		*cyl;
	t_vertex	pt;
	float		t;
	t_vector	normal;
	float		ctr_vtx_distance;

	cyl = hit->obj->shape.cyl;
	ctr_vtx_distance = vtx_distance(hit->vtx, cyl->base.ctr);
	if (ctr_vtx_distance < cyl->radius 
		&& ctr_vtx_distance < vtx_distance(hit->vtx, cyl->top.ctr))
		normal = cyl->base.norm;
	else if (vtx_distance(hit->vtx, cyl->top.ctr) < cyl->radius)
		normal = cyl->top.norm;
	else
	{
		t = dot_prod(vec_between(cyl->base.ctr, hit->vtx),
				vec_unit(cyl->axis));
		pt = vtx_translate(cyl->base.ctr, vec_multiply(cyl->axis, t));
		normal = vec_between(pt, hit->vtx);
	}
	return (normal);
}

static t_vector	plane_normal(t_hit *hit)
{
	t_vector	normal;

	normal = hit->obj->shape.plane->norm;
	return (normal);
}

static t_vector	cone_normal(t_hit *hit)
{
	t_cone		*cone;
	t_vertex	pt;
	float		t;
	t_vector	normal;

	cone = hit->obj->shape.cone;
	if (dot_prod(vec_between(hit->vtx, cone->top.ctr), cone->axis) < 0.001)
		normal = cone->axis;
	else
	{
		t = dot_prod(vec_between(cone->ctr, hit->vtx),
				vec_unit(cone->axis));
		t *= cone->ctr_half_angle_tan_sqrd_plus_one;
		pt = vtx_translate(cone->ctr, vec_multiply(cone->axis, t));
		normal = vec_between(pt, hit->vtx);
	}
	return (normal);
}
