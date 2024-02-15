/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:33:29 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:04:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viewport.h"

void	set_plane(t_plane *pln, t_viewport *vp, t_cam *cam)
{
	pln->ctr = vp->ctr;
	pln->cam_ctr_vec = vec_between(vp->cam, pln->ctr);
	pln->ctr_cam_vec = vec_inv(pln->cam_ctr_vec);
	pln->inv_norm = cam->dir;
	pln->norm = vec_inv(pln->inv_norm);
}

void	set_size(t_viewport *vp, float width, float height)
{
	vp->width = width;
	vp->height = height;
}

void	link_focal_point(t_viewport *vp, t_cam *cam)
{
	vp->cam = new_vertex(cam->pos.x, cam->pos.y, cam->pos.z);
}
