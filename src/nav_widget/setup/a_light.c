/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:04:04 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/29 14:33:47 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_parent(t_nav *nav, t_nav *parent)
{
	parent->child = nav;
	(nav[0]).parent = parent;
	(nav[1]).parent = parent;
}

static void	link_data(t_nav *nav, t_lux *lux)
{
	(nav[2]).cont.float_number = &lux->bright;
	(nav[3]).cont.uint_number = &lux->color.red;
	(nav[4]).cont.uint_number = &lux->color.green;
	(nav[5]).cont.uint_number = &lux->color.blue;
}

static void	link_nodes(t_nav *nav)
{
	set_nav(nav, NAVFLT, "BRIGHTNESS", nav_dir(0, 1, -1, 2));
	set_nav(nav, NAV3INT, "COLOR", nav_dir(1, 0, -1, 3));
	set_nav(nav, NAVFLT, "", nav_dir(2, 2, 0, -1));
	set_nav(nav, NAVINT, "Red", nav_dir(3, 4, 1, -1));
	set_nav(nav, NAVINT, "Green", nav_dir(4, 5, 1, -1));
	set_nav(nav, NAVINT, "Blue", nav_dir(5, 3, 1, -1));
}

static void	link_leaves(t_nav *nav, t_nav *dt_nav)
{
	nav[2].child = &dt_nav[INFIELD_1];
	nav[3].child = &dt_nav[INFIELD_1];
	nav[4].child = &dt_nav[INFIELD_2];
	nav[5].child = &dt_nav[INFIELD_3];
}

int	nav_a_light(t_nav *parent, t_lux *lux, t_data *dt)
{
	t_nav	*nav;

	set_desc("AMBIENT", parent);
	nav = malloc(6 * sizeof(t_nav));
	if (!nav)
		return (FAILURE);
	ft_bzero(nav, 6 * sizeof(t_nav));
	link_nodes(nav);
	link_data(nav, lux);
	link_parent(nav, parent);
	set_pos_rt(nav, parent, 2);
	set_act(nav, 2, input_mode_init);
	link_leaves(nav, dt->nav);
	return (SUCCESS);
}
