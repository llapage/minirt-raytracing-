/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:33:29 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:03:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viewport.h"

void	calculate_horizontal_orientation(t_viewport *vp, t_cam *cam)
{
	if (vec_is_y_axis(cam->dir))
		vp->u_vec = vec_cross(cam->dir, new_vector(0, 0, 1));
	else
		vp->u_vec = vec_cross(cam->dir, new_vector(0, 1, 0));
	vp->u_vec = vec_unit(vp->u_vec);
	vp->u_vec = vec_multiply(vp->u_vec, vp->width);
}

void	calculate_vertical_orientation(t_viewport *vp, t_cam *cam)
{
	vp->v_vec = vec_cross(cam->dir, vp->u_vec);
	vp->v_vec = vec_unit(vp->v_vec);
	vp->v_vec = vec_multiply(vp->v_vec, vp->height);
}

void	calculate_top_left_corner_position(t_viewport *vp, t_cam *cam)
{
	t_vector	temp;

	vp->top_left_corn = vtx_translate(cam->pos,
			vec_multiply(cam->dir, vp->focal_len));
	temp = vec_divide(vp->u_vec, 2);
	vp->top_left_corn = vtx_translate(vp->top_left_corn, vec_inv(temp));
	temp = vec_divide(vp->v_vec, 2);
	vp->top_left_corn = vtx_translate(vp->top_left_corn, vec_inv(temp));
}

void	calculate_top_left_pixel_projection_position(t_viewport *vp)
{
	t_vector	temp;
	float		rat_diff;

	vp->b_offs = 0;
	vp->supsam = round_next_square(SUPERSAMPLES);
	vp->sqrt_supsam = sqrt(vp->supsam);
	temp = vec_add(vp->px_delt_u, vp->px_delt_v);
	temp = vec_multiply(temp, ((1.0 / vp->supsam) / 2));
	vp->top_left_px = vtx_translate(vp->top_left_corn, temp);
	rat_diff = ((float)S_HEIGHT * vp->width) / ((float)S_WIDTH * vp->height);
	if (rat_diff < 1.0)
		vp->top_left_px = vtx_translate(vp->top_left_px,
				vec_multiply(vp->v_vec, 
					(1.0 - rat_diff) / 2));
	else
		vp->b_offs = (S_HEIGHT - (S_HEIGHT / rat_diff)) / 2.0;
}
