/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:59:37 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 19:57:43 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_plane	new_plane(t_vertex vtx, t_vector vec, t_vertex	cam)
{
	t_plane	pln;

	pln.ctr = vtx;
	pln.norm = vec;
	pln.inv_norm = vec_inv(pln.norm);
	pln.cam_ctr_vec = vec_between(cam, pln.ctr);
	pln.ctr_cam_vec = vec_inv(pln.cam_ctr_vec);
	return (pln);
}

t_vertex	next_sub_px(t_data *dt)
{
	t_vector	u_offset;
	t_vector	v_offset;
	t_vector	tot_offset;
	t_viewport	*vp;

	vp = dt->vp;
	u_offset = vec_multiply(vp->px_delt_u, 
			(float)dt->sub_col / vp->sqrt_supsam);
	v_offset = vec_multiply(vp->px_delt_v, 
			(float)dt->sub_line / vp->sqrt_supsam);
	tot_offset = vec_add(u_offset, v_offset);
	dt->sub_px = vtx_translate(dt->vp_vtx, tot_offset);
	return (dt->sub_px);
}

t_vertex	px_to_vp(t_pixel px, t_data *dt)
{
	t_vector	u_offset;
	t_vector	v_offset;
	t_vector	tot_offset;

	u_offset = vec_multiply(dt->vp->px_delt_u, px.x);
	v_offset = vec_multiply(dt->vp->px_delt_v, px.y);
	tot_offset = vec_add(u_offset, v_offset);
	dt->vp_vtx = vtx_translate(dt->vp->top_left_px, tot_offset);
	return (dt->vp_vtx);
}

t_range	new_range(float min, float max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

int	within_range(float a, t_range range)
{
	if (a >= range.min && a <= range.max)
		return (1);
	return (0);
}
