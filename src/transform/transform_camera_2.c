/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_camera_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:32 by llapage           #+#    #+#             */
/*   Updated: 2023/12/28 19:16:28 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	move_cam_q(t_data *data)
{
	float	scale_x;
	float	scale_z;

	scale_x = 1 - data->scene->cam->dir.x;
	scale_z = 1 - data->scene->cam->dir.z;
	if (data->scene->cam->dir.x < -0.5)
		scale_x = -1 - data->scene->cam->dir.x;
	if (data->scene->cam->dir.z < -0.5)
		scale_z = -1 - data->scene->cam->dir.z;
	if ((data->scene->cam->dir.x < 0.5 && data->scene->cam->dir.x >= 0)
		|| (data->scene->cam->dir.x > -0.5 && data->scene->cam->dir.x <= 0))
		scale_x = data->scene->cam->dir.x;
	if ((data->scene->cam->dir.z < 0.5 && data->scene->cam->dir.z >= 0)
		|| (data->scene->cam->dir.z > -0.5 && data->scene->cam->dir.z <= 0))
		scale_z = data->scene->cam->dir.z;
	data->scene->cam->pos = new_vertex(
			data->scene->cam->pos.x + 2 * scale_x,
			data->scene->cam->pos.y + 2 * (1 - data->scene->cam->dir.y),
			data->scene->cam->pos.z + 2 * scale_z);
}

void	move_cam_e(t_data *data)
{
	float	scale_x;
	float	scale_z;

	scale_x = 1 - data->scene->cam->dir.x;
	scale_z = 1 - data->scene->cam->dir.z;
	if (data->scene->cam->dir.x < -0.5)
		scale_x = -1 - data->scene->cam->dir.x;
	if (data->scene->cam->dir.z < -0.5)
		scale_z = -1 - data->scene->cam->dir.z;
	if ((data->scene->cam->dir.x < 0.5 && data->scene->cam->dir.x >= 0)
		|| (data->scene->cam->dir.x > -0.5 && data->scene->cam->dir.x <= 0))
		scale_x = data->scene->cam->dir.x;
	if ((data->scene->cam->dir.z < 0.5 && data->scene->cam->dir.z >= 0)
		|| (data->scene->cam->dir.z > -0.5 && data->scene->cam->dir.z <= 0))
		scale_z = data->scene->cam->dir.z;
	data->scene->cam->pos = new_vertex(
			data->scene->cam->pos.x - 2 * scale_x,
			data->scene->cam->pos.y - 2 * (1 - data->scene->cam->dir.y),
			data->scene->cam->pos.z - 2 * scale_z);
}
