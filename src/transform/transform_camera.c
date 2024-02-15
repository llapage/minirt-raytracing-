/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:06:44 by llapage           #+#    #+#             */
/*   Updated: 2023/12/28 19:11:44 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

static void	move_cam_w(t_data *dt)
{
	dt->scene->cam->pos = new_vertex(
			dt->scene->cam->pos.x + 2 * dt->scene->cam->dir.x,
			dt->scene->cam->pos.y + 2 * dt->scene->cam->dir.y,
			dt->scene->cam->pos.z + 2 * dt->scene->cam->dir.z);
}

static void	move_cam_a(t_data *dt)
{
	dt->scene->cam->pos = new_vertex(
			dt->scene->cam->pos.x - 2 * -(dt->scene->cam->dir.z),
			dt->scene->cam->pos.y + 0 * dt->scene->cam->dir.y,
			dt->scene->cam->pos.z + 2 * dt->scene->cam->dir.x);
}

static void	move_cam_s(t_data *dt)
{
	dt->scene->cam->pos = new_vertex(
			dt->scene->cam->pos.x - 2 * dt->scene->cam->dir.x,
			dt->scene->cam->pos.y - 2 * dt->scene->cam->dir.y,
			dt->scene->cam->pos.z - 2 * dt->scene->cam->dir.z);
}

static void	move_cam_d(t_data *dt)
{
	dt->scene->cam->pos = new_vertex(
			dt->scene->cam->pos.x - 2 * dt->scene->cam->dir.z,
			dt->scene->cam->pos.y + 0 * dt->scene->cam->dir.y,
			dt->scene->cam->pos.z + 2 * -(dt->scene->cam->dir.x));
}

void	move_cam(int keycode, t_data *dt)
{
	save_state(&(dt->scene->cam->pos), VTX, dt);
	if (keycode == W_KEY)
		move_cam_w(dt);
	else if (keycode == S_KEY)
		move_cam_s(dt);
	else if (keycode == A_KEY)
		move_cam_a(dt);
	else if (keycode == D_KEY)
		move_cam_d(dt);
	else if (keycode == Q_KEY)
		move_cam_q(dt);
	else if (keycode == E_KEY)
		move_cam_e(dt);
	save_state(dt->vp, VP, dt);
	init_vp(dt->vp, dt->scene->cam);
	edit_mode(dt);
	render(dt);
	show_str(dt, "Press enter to render", 
		pix_l(S_WIDTH / 2 - 60, S_HEIGHT - 20), GREY);
}
