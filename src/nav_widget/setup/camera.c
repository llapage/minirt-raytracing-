/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:45:07 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/29 14:29:50 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_data(t_data *dt)
{
	dt->nav[3].cont.cam = dt->scene->cam;
	(dt->nav[7]).cont.float_number = &dt->scene->cam->pos.x;
	(dt->nav[8]).cont.float_number = &dt->scene->cam->pos.y;
	(dt->nav[9]).cont.float_number = &dt->scene->cam->pos.z;
	(dt->nav[10]).cont.float_number = &dt->scene->cam->dir.x;
	(dt->nav[11]).cont.float_number = &dt->scene->cam->dir.y;
	(dt->nav[12]).cont.float_number = &dt->scene->cam->dir.z;
	(dt->nav[13]).cont.uint_number = &dt->scene->cam->fov;
}

static void	link_nodes(t_data *dt)
{
	set_nav(dt->nav, NAVCAM, "CAMERA", nav_dir(3, 23, 0, 4));
	set_nav(dt->nav, NAV3FLT, "LOCATION", nav_dir(4, 5, 3, 7));
	set_nav(dt->nav, NAV3FLT, "ORIENTATION", nav_dir(5, 6, 3, 10));
	set_nav(dt->nav, NAVINT, "FOV", nav_dir(6, 4, 3, 13));
	set_nav(dt->nav, NAVFLT, "X", nav_dir(7, 8, 4, -1));
	set_nav(dt->nav, NAVFLT, "Y", nav_dir(8, 9, 4, -1));
	set_nav(dt->nav, NAVFLT, "Z", nav_dir(9, 7, 4, -1));
	set_nav(dt->nav, NAVFLT, "X", nav_dir(10, 11, 5, -1));
	set_nav(dt->nav, NAVFLT, "Y", nav_dir(11, 12, 5, -1));
	set_nav(dt->nav, NAVFLT, "Z", nav_dir(12, 10, 5, -1));
	set_nav(dt->nav, NAVINT, "", nav_dir(13, 13, 6, -1));
}

void	set_cam_act(t_nav *nav)
{
	nav[4].act = input_mode_init;
	nav[5].act = input_mode_init;
	nav[6].act = input_mode_init;
}

void	link_leaves(t_data *dt)
{
	dt->nav[7].child = &dt->nav[INFIELD_1];
	dt->nav[8].child = &dt->nav[INFIELD_2];
	dt->nav[9].child = &dt->nav[INFIELD_3];
	dt->nav[10].child = &dt->nav[INFIELD_1];
	dt->nav[11].child = &dt->nav[INFIELD_2];
	dt->nav[12].child = &dt->nav[INFIELD_3];
	dt->nav[13].child = &dt->nav[INFIELD_1];
}

void	nav_cam(t_data *dt)
{
	link_nodes(dt);
	link_data(dt);
	dt->nav[3].cont_type = CAM;
	link_leaves(dt);
	set_cam_pos(dt->nav);
	set_cam_act(dt->nav);
}
