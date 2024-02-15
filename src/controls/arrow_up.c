/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:05:15 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 17:38:56 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	press_arrow_up(t_data *dt)
{
	float	angle;

	angle = (float)dt->scene->cam->fov / 80.0;
	save_cam_and_vp_state(dt);
	tilt(angle, dt);
	init_vp(dt->vp, dt->scene->cam);
	edit_mode(dt);
	render(dt);
	unset_current_object(dt);
}
