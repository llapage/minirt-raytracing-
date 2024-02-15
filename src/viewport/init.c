/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:33:29 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:02:15 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viewport.h"

void	init_vp(t_viewport *vp, t_cam *cam)
{
	set_size(vp, VP_WIDTH, VP_HEIGHT);
	calculate_focal_length(vp, cam);
	calculate_diagonal_field_of_view(vp);
	link_focal_point(vp, cam);
	calculate_centre(vp, cam);
	calculate_horizontal_orientation(vp, cam);
	calculate_vertical_orientation(vp, cam);
	calculate_distance_between_projected_screen_pixels(vp);
	calculate_top_left_corner_position(vp, cam);
	calculate_top_left_pixel_projection_position(vp);
	set_plane(&vp->pln, vp, cam);
}
