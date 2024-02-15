/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 11:06:36 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	set_cyl_cam_vars(t_cyl *cyl, t_vertex cam_pos)
{
	cyl->cam_ctr_vec = vec_between(cam_pos, cyl->ctr);
	cyl->ctr_cam_vec = vec_inv(cyl->cam_ctr_vec);
	cyl->top.cam_ctr_vec = vec_between(cam_pos, cyl->top.ctr);
	cyl->top.ctr_cam_vec = vec_inv(cyl->top.cam_ctr_vec);
	cyl->top.ctr_cam_dot_norm = dot_prod(cyl->top.ctr_cam_vec, cyl->top.norm);
	cyl->base.cam_ctr_vec = vec_between(cam_pos, cyl->base.ctr);
	cyl->base.ctr_cam_vec = vec_inv(cyl->base.cam_ctr_vec);
	cyl->base.ctr_cam_sqlen = vec_sqlen(cyl->base.ctr_cam_vec);
	cyl->base.ctr_cam_dot_norm = dot_prod(cyl->base.ctr_cam_vec, 
			vec_inv(cyl->base.norm));
	cyl->base.ctr_cam_dot_norm_sqrd = pow(cyl->base.ctr_cam_dot_norm, 2);
	cyl->base.trinomial_c = cyl->base.ctr_cam_sqlen
		- cyl->base.ctr_cam_dot_norm_sqrd
		- cyl->radius_sqrd;
}

void	set_cone_cam_vars(t_cone *cone, t_vertex cam_pos)
{
	cone->cam_ctr_vec = vec_between(cam_pos, cone->ctr);
	cone->ctr_cam_vec = vec_inv(cone->cam_ctr_vec);
	cone->ctr_cam_dot_norm = dot_prod(cone->ctr_cam_vec, cone->axis);
	cone->ctr_cam_dot_norm_sqrd = pow(cone->ctr_cam_dot_norm, 2);
	cone->top.cam_ctr_vec = vec_between(cam_pos, cone->top.ctr);
	cone->top.ctr_cam_vec = vec_inv(cone->top.cam_ctr_vec);
	cone->top.ctr_cam_sqlen = vec_sqlen(cone->top.ctr_cam_vec);
	cone->top.ctr_cam_dot_norm = dot_prod(cone->top.ctr_cam_vec, 
			cone->top.norm);
	cone->top.ctr_cam_dot_norm_sqrd = pow(cone->top.ctr_cam_dot_norm, 2);
	cone->ctr_half_angle_tan_sqrd_plus_one_times_ctr_cam_dot_norm 
		= cone->ctr_half_angle_tan_sqrd_plus_one
		* cone->ctr_cam_dot_norm;
	cone->ctr_half_angle_tan_sqrd_plus_one_times_ctr_cam_dot_norm_sqrd
		= cone->ctr_half_angle_tan_sqrd_plus_one
		* cone->ctr_cam_dot_norm_sqrd;
	cone->trinomial_c = vec_sqlen(cone->ctr_cam_vec)
		- cone->ctr_half_angle_tan_sqrd_plus_one_times_ctr_cam_dot_norm_sqrd;
}

void	set_sphere_cam_vars(t_sphere *sphere, t_vertex cam_pos)
{
	sphere->cam_ctr_vec = vec_between(cam_pos, sphere->ctr);
	sphere->ctr_cam_vec = vec_inv(sphere->cam_ctr_vec);
	sphere->ctr_cam_sqlen = vec_sqlen(sphere->ctr_cam_vec);
	sphere->trinomial_c = sphere->ctr_cam_sqlen - sphere->radius_sqrd;
}

void	set_plane_cam_vars(t_plane *plane, t_vertex cam_pos)
{
	plane->cam_ctr_vec = vec_between(cam_pos, plane->ctr);
	plane->ctr_cam_vec = vec_inv(plane->cam_ctr_vec);
	plane->ctr_cam_sqlen = vec_sqlen(plane->ctr_cam_vec);
	plane->ctr_cam_dot_norm = dot_prod(plane->ctr_cam_vec, plane->norm);
}

void	set_cam_vars(t_data *dt, t_vertex cam_pos)
{
	t_obj	*obj;

	obj = dt->scene->obj;
	while (obj)
	{
		save_obj_state(obj, dt);
		if (obj->type == CYL)
			set_cyl_cam_vars(obj->shape.cyl, cam_pos);
		else if (obj->type == SPHERE)
			set_sphere_cam_vars(obj->shape.sphere, cam_pos);
		else if (obj->type == PLANE)
			set_plane_cam_vars(obj->shape.plane, cam_pos);
		else if (obj->type == CONE)
			set_cone_cam_vars(obj->shape.cone, cam_pos);
		obj = obj->next;
	}
}
