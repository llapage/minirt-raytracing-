/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 16:22:28 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	set_cyl_vars(t_cyl *cyl, t_data *dt)
{
	cyl->radius = cyl->diameter / 2;
	cyl->radius_sqrd = pow(cyl->radius, 2);
	cyl->top.norm = cyl->axis;
	cyl->top.ctr = vtx_translate(cyl->ctr, vec_multiply(cyl->top.norm,
				cyl->height / 2));
	cyl->base.norm = vec_inv(cyl->axis);
	cyl->base.ctr = vtx_translate(cyl->ctr, vec_multiply(cyl->base.norm,
				cyl->height / 2));
	cyl->rim_dist = sqrt(pow(cyl->height / 2, 2) + pow(cyl->radius, 2));
	set_cyl_cam_vars(cyl, dt->scene->cam->pos);
}

void	set_cone_vars(t_cone *cone, t_data *dt)
{
	cone->radius = cone->diameter / 2.0;
	cone->slant_len = sqrt(pow(cone->radius, 2.0) + pow(cone->height, 2.0));
	cone->ctr_half_angle = acos(cone->height / cone->slant_len);
	cone->ctr_half_angle_tan = tan(cone->ctr_half_angle);
	cone->ctr_half_angle_tan_sqrd = pow(cone->ctr_half_angle_tan, 2.0);
	cone->ctr_half_angle_tan_sqrd_plus_one = 1.0 
		+ cone->ctr_half_angle_tan_sqrd;
	cone->slant_angle = asin(cone->height / cone->slant_len);
	cone->top.ctr = vtx_translate(cone->ctr, vec_multiply(cone->axis,
				cone->height));
	cone->top.norm = cone->axis;
	set_cone_cam_vars(cone, dt->scene->cam->pos);
}

void	set_sphere_vars(t_sphere *sphere, t_data *dt)
{
	sphere->radius = sphere->diameter / 2;
	sphere->radius_sqrd = pow(sphere->radius, 2);
	set_sphere_cam_vars(sphere, dt->scene->cam->pos);
}

void	set_plane_vars(t_plane *plane, t_data *dt)
{
	plane->inv_norm = vec_inv(plane->norm);
	set_plane_cam_vars(plane, dt->scene->cam->pos);
}

void	set_vars(t_data *dt)
{
	t_obj	*obj;

	save_state(&dt->vp, VP, dt); 
	range_wrap_scene(dt->scene);
	init_vp(dt->vp, dt->scene->cam);
	obj = dt->scene->obj;
	while (obj != NULL)
	{
		save_obj_state(obj, dt);
		if (obj->type == CYL)
			set_cyl_vars(obj->shape.cyl, dt);
		else if (obj->type == SPHERE)
			set_sphere_vars(obj->shape.sphere, dt);
		else if (obj->type == PLANE)
			set_plane_vars(obj->shape.plane, dt);
		else if (obj->type == CONE)
			set_cone_vars(obj->shape.cone, dt);
		obj = obj->next;
	}
}
