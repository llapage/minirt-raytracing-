/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:33:29 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 22:51:32 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viewport.h"

void	calculate_focal_length(t_viewport *vp, t_cam *cam)
{
	vp->focal_len = (vp->width / 2.0) / tan(((float)cam->fov / 2.0) 
			* (M_PI / 180.0));
}

void	calculate_diagonal_field_of_view(t_viewport *vp)
{
	vp->diag_fov = (180.0 / M_PI) * 2 * atan(sqrt(pow(vp->width / 2, 2) 
				+ pow(vp->height / 2, 2)) / vp->focal_len);
}

void	calculate_centre(t_viewport *vp, t_cam *cam)
{
	vp->ctr = vtx_translate(vp->cam, vec_multiply(cam->dir, vp->focal_len));
}

void	calculate_distance_between_projected_screen_pixels(t_viewport *vp)
{
	vp->px_delt_u = vec_divide(vp->u_vec, S_WIDTH);
	vp->px_delt_v = vec_multiply(vec_unit(vp->v_vec), 
			vec_magnitude(vp->px_delt_u));
}
