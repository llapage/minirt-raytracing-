/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:58:55 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/29 14:31:14 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_parent(t_nav *nav, t_nav *parent)
{
	parent->child = nav;
	(nav[0]).parent = parent;
	(nav[1]).parent = parent;
	(nav[2]).parent = parent;
	(nav[3]).parent = parent;
	(nav[4]).parent = parent;
	(nav[5]).parent = parent;
}

static void	link_data(t_nav *nav, t_obj *obj)
{
	(nav[4]).cont.uint_number = &obj->fill;
	(nav[5]).cont.uint_number = &obj->surface;
	(nav[6]).cont.float_number = &obj->shape.sphere->ctr.x;
	(nav[7]).cont.float_number = &obj->shape.sphere->ctr.y;
	(nav[8]).cont.float_number = &obj->shape.sphere->ctr.z;
	(nav[9]).cont.float_number = &obj->shape.sphere->diameter;
	(nav[10]).cont.uint_number = &obj->color.red;
	(nav[11]).cont.uint_number = &obj->color.green;
	(nav[12]).cont.uint_number = &obj->color.blue;
	(nav[13]).cont.uint_number = &obj->gloss;
	(nav[14]).cont.uint_number = &obj->refness;
}

static void	link_nodes(t_nav *nav)
{
	set_nav(nav, NAV3FLT, "LOCATION", nav_dir(0, 1, -1, 6));
	set_nav(nav, NAVFLT, "DIAMETER", nav_dir(1, 2, -1, 9));
	set_nav(nav, NAV3INT, "COLOR", nav_dir(2, 3, -1, 10));
	set_nav(nav, NAV2INT, "GLOSS", nav_dir(3, 4, -1, 13));
	set_nav(nav, NAVINT, "FILL", nav_dir(4, 5, -1, -1));
	set_nav(nav, NAVINT, "SURFACE", nav_dir(5, 0, -1, -1));
	set_nav(nav, NAVFLT, "X", nav_dir(6, 7, 0, -1));
	set_nav(nav, NAVFLT, "Y", nav_dir(7, 8, 0, -1));
	set_nav(nav, NAVFLT, "Z", nav_dir(8, 6, 0, -1));
	set_nav(nav, NAVFLT, "", nav_dir(9, 9, 1, -1));
	set_nav(nav, NAVINT, "Red", nav_dir(10, 11, 2, -1));
	set_nav(nav, NAVINT, "Green", nav_dir(11, 12, 2, -1));
	set_nav(nav, NAVINT, "Blue", nav_dir(12, 10, 2, -1));
	set_nav(nav, NAVINT, "S", nav_dir(13, 14, 3, -1));
	set_nav(nav, NAVINT, "R", nav_dir(14, 13, 3, -1));
}

static void	link_leaves(t_nav *nav, t_nav *dt_nav)
{
	nav[6].child = &dt_nav[INFIELD_1];
	nav[7].child = &dt_nav[INFIELD_2];
	nav[8].child = &dt_nav[INFIELD_3];
	nav[9].child = &dt_nav[INFIELD_1];
	nav[10].child = &dt_nav[INFIELD_1];
	nav[11].child = &dt_nav[INFIELD_2];
	nav[12].child = &dt_nav[INFIELD_3];
	nav[13].child = &dt_nav[INFIELD_1];
	nav[14].child = &dt_nav[INFIELD_2];
}

int	nav_sphere(t_nav *parent, t_obj *obj, t_data *dt)
{
	t_nav	*nav;

	set_desc("SPHERE", parent);
	nav = malloc(15 * sizeof(t_nav));
	if (!nav)
		return (FAILURE);
	ft_bzero(nav, 15 * sizeof(t_nav));
	link_nodes(nav);
	link_data(nav, obj);
	link_parent(nav, parent);
	set_pos_rt(nav, parent, 6);
	set_act(nav, 4, input_mode_init);
	nav[4].scr = scroll_fill;
	nav[5].scr = scroll_surface;
	link_leaves(nav, dt->nav);
	return (SUCCESS);
}