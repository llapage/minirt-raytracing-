/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:10:15 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/29 14:34:19 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_parent(t_nav *nav, t_nav *parent)
{
	parent->child = nav;
	(nav[0]).parent = parent;
	(nav[1]).parent = parent;
	(nav[2]).parent = parent;
}

static void	link_data(t_nav *nav, t_lux *lux)
{
	(nav[3]).cont.float_number = &lux->src.dir->dir.x;
	(nav[4]).cont.float_number = &lux->src.dir->dir.y;
	(nav[5]).cont.float_number = &lux->src.dir->dir.z;
	(nav[6]).cont.float_number = &lux->bright;
	(nav[7]).cont.uint_number = &lux->color.red;
	(nav[8]).cont.uint_number = &lux->color.green;
	(nav[9]).cont.uint_number = &lux->color.blue;
}

static void	link_nodes(t_nav *nav)
{
	set_nav(nav, NAV3FLT, "DIRECTION", nav_dir(0, 1, -1, 3));
	set_nav(nav, NAVFLT, "BRIGHTNESS", nav_dir(1, 2, -1, 6));
	set_nav(nav, NAV3INT, "COLOR", nav_dir(2, 0, -1, 7));
	set_nav(nav, NAVFLT, "X", nav_dir(3, 4, 0, -1));
	set_nav(nav, NAVFLT, "Y", nav_dir(4, 5, 0, -1));
	set_nav(nav, NAVFLT, "Z", nav_dir(5, 3, 0, -1));
	set_nav(nav, NAVFLT, "", nav_dir(6, 6, 1, -1));
	set_nav(nav, NAVINT, "Red", nav_dir(7, 8, 2, -1));
	set_nav(nav, NAVINT, "Green", nav_dir(8, 9, 2, -1));
	set_nav(nav, NAVINT, "Blue", nav_dir(9, 7, 2, -1));
}

static void	link_leaves(t_nav *nav, t_nav *dt_nav)
{
	nav[3].child = &dt_nav[INFIELD_1];
	nav[4].child = &dt_nav[INFIELD_2];
	nav[5].child = &dt_nav[INFIELD_3];
	nav[6].child = &dt_nav[INFIELD_1];
	nav[7].child = &dt_nav[INFIELD_1];
	nav[8].child = &dt_nav[INFIELD_2];
	nav[9].child = &dt_nav[INFIELD_3];
}

int	nav_d_light(t_nav *parent, t_lux *lux, t_data *dt)
{
	t_nav	*nav;

	set_desc("DIRECTIONAL", parent);
	nav = malloc(10 * sizeof(t_nav));
	if (!nav)
		return (FAILURE);
	ft_bzero(nav, 10 * sizeof(t_nav));
	link_nodes(nav);
	link_data(nav, lux);
	link_parent(nav, parent);
	set_pos_rt(nav, parent, 3);
	set_act(nav, 3, input_mode_init);
	link_leaves(nav, dt->nav);
	return (SUCCESS);
}
