/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_translation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:23:14 by llapage           #+#    #+#             */
/*   Updated: 2023/12/22 16:29:50 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	transform_sphere(t_data *dt)
{
	t_vector	dir;

	save_state(&dt->curr_obj->shape.sphere->ctr, VTX, dt);
	save_state(&dt->curr_obj->shape.sphere->cam_ctr_vec, VEC, dt);
	dir = new_vector(dt->x_diff / 10, dt->y_diff / 10, 0);
	*dt->curr_obj->ctr
		= vtx_translate(dt->curr_obj->shape.sphere->ctr, dir);
}

void	obj_translate(t_pixel ptr, t_hit ht, t_data *dt)
{
	t_ray		ray;
	t_plane		pln;
	float		dist;
	t_vertex	hit;
	t_vertex	ctr;

	ptr.y -= dt->vp->b_offs;
	ray = ray_between(dt->vp->cam, px_to_vp(ptr, dt));
	pln = new_plane(ht.vtx, vec_inv(dt->scene->cam->dir), dt->vp->cam);
	set_plane_vars(&pln, dt);
	dist = intersect_plane(ray, &pln, dt->visib);
	hit = vtx_translate(dt->vp->cam, vec_multiply(ray.unit, dist));
	ctr = vtx_translate(hit, vec_inv(ht.ctr_hit_vec));
	save_state(ht.obj, ht.obj->type, dt);
	*dt->curr_obj->ctr = ctr;
}
