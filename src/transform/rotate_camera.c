/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:45:45 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

static void	pan_and_tilt(t_pixel screen_displacement, t_data *dt);

void	rotate_camera(t_pixel screen_displacement, t_data *dt)
{
	save_cam_and_vp_state(dt);
	pan_and_tilt(screen_displacement, dt);
	init_vp(dt->vp, dt->scene->cam);
}

static void	pan_and_tilt(t_pixel screen_displacement, t_data *dt)
{
	float	pan_angle;
	float	tilt_angle;

	pan_angle = ((float)screen_displacement.x
			/ (float)S_WIDTH) * dt->scene->cam->fov;
	tilt_angle = -((float)screen_displacement.y
			/ (float)S_WIDTH) * dt->scene->cam->fov;
	pan(pan_angle, dt);
	tilt(tilt_angle, dt);
}
