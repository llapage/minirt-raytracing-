/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:45:21 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/29 14:30:25 by mde-clee         ###   ########.fr       */
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
	(nav[6]).parent = parent;
	(nav[7]).parent = parent;
}

static void	link_data(t_nav *nav, t_obj *obj)
{
	(nav[6]).cont.uint_number = &obj->fill;
	(nav[7]).cont.uint_number = &obj->surface;
	(nav[8]).cont.float_number = &obj->shape.cyl->ctr.x;
	(nav[9]).cont.float_number = &obj->shape.cyl->ctr.y;
	(nav[10]).cont.float_number = &obj->shape.cyl->ctr.z;
	(nav[11]).cont.float_number = &obj->shape.cyl->axis.x;
	(nav[12]).cont.float_number = &obj->shape.cyl->axis.y;
	(nav[13]).cont.float_number = &obj->shape.cyl->axis.z;
	(nav[14]).cont.float_number = &obj->shape.cyl->diameter;
	(nav[15]).cont.float_number = &obj->shape.cyl->height;
	(nav[16]).cont.uint_number = &obj->color.red;
	(nav[17]).cont.uint_number = &obj->color.green;
	(nav[18]).cont.uint_number = &obj->color.blue;
	(nav[19]).cont.uint_number = &obj->gloss;
	(nav[20]).cont.uint_number = &obj->refness;
}

static void	link_nodes(t_nav *nav)
{
	set_nav(nav, NAV3FLT, "LOCATION", nav_dir(0, 1, -1, 8));
	set_nav(nav, NAV3FLT, "ORIENTATION", nav_dir(1, 2, -1, 11));
	set_nav(nav, NAVFLT, "DIAMETER", nav_dir(2, 3, -1, 14));
	set_nav(nav, NAVFLT, "HEIGHT", nav_dir(3, 4, -1, 15));
	set_nav(nav, NAV3INT, "COLOR", nav_dir(4, 5, -1, 16));
	set_nav(nav, NAV2INT, "GLOSS", nav_dir(5, 6, -1, 19));
	set_nav(nav, NAVINT, "FILL", nav_dir(6, 7, -1, -1));
	set_nav(nav, NAVINT, "SURFACE", nav_dir(7, 0, -1, -1));
	set_nav(nav, NAVFLT, "X", nav_dir(8, 9, 0, -1));
	set_nav(nav, NAVFLT, "Y", nav_dir(9, 10, 0, -1));
	set_nav(nav, NAVFLT, "Z", nav_dir(10, 8, 0, -1));
	set_nav(nav, NAVFLT, "X", nav_dir(11, 12, 1, -1));
	set_nav(nav, NAVFLT, "Y", nav_dir(12, 13, 1, -1));
	set_nav(nav, NAVFLT, "Z", nav_dir(13, 11, 1, -1));
	set_nav(nav, NAVFLT, "", nav_dir(14, 14, 2, -1));
	set_nav(nav, NAVFLT, "", nav_dir(15, 15, 3, -1));
	set_nav(nav, NAVINT, "Red", nav_dir(16, 17, 4, -1));
	set_nav(nav, NAVINT, "Green", nav_dir(17, 18, 4, -1));
	set_nav(nav, NAVINT, "Blue", nav_dir(18, 16, 4, -1));
	set_nav(nav, NAVINT, "S", nav_dir(19, 20, 5, -1));
	set_nav(nav, NAVINT, "R", nav_dir(20, 19, 5, -1));
}

static void	link_leaves(t_nav *nav, t_nav *dt_nav)
{
	nav[8].child = &dt_nav[INFIELD_1];
	nav[9].child = &dt_nav[INFIELD_2];
	nav[10].child = &dt_nav[INFIELD_3];
	nav[11].child = &dt_nav[INFIELD_1];
	nav[12].child = &dt_nav[INFIELD_2];
	nav[13].child = &dt_nav[INFIELD_3];
	nav[14].child = &dt_nav[INFIELD_1];
	nav[15].child = &dt_nav[INFIELD_1];
	nav[16].child = &dt_nav[INFIELD_1];
	nav[17].child = &dt_nav[INFIELD_2];
	nav[18].child = &dt_nav[INFIELD_3];
	nav[19].child = &dt_nav[INFIELD_1];
	nav[20].child = &dt_nav[INFIELD_2];
}

int	nav_cyl(t_nav *parent, t_obj *obj, t_data *dt)
{
	t_nav	*nav;

	set_desc("CYLINDER", parent);
	nav = malloc(21 * sizeof(t_nav));
	if (!nav)
		return (FAILURE);
	ft_bzero(nav, 21 * sizeof(t_nav));
	link_nodes(nav);
	link_data(nav, obj);
	link_parent(nav, parent);
	set_pos_rt(nav, parent, 8);
	set_act(nav, 6, input_mode_init);
	link_leaves(nav, dt->nav);
	return (SUCCESS);
}
