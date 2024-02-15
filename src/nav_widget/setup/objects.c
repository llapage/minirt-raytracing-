/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:39:55 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:33:01 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_tail(t_nav *nav, t_data *dt)
{
	nav = (dt->nav[NAVOBJECTS]).child;
	while (nav->sibling)
		nav = nav->sibling;
	nav->sibling = (dt->nav[NAVOBJECTS]).child;
}

static void	link_nodes_2(t_nav *nav, t_data *dt)
{
	t_nav	*lst;

	lst = dt->nav[NAVOBJECTS].child;
	if (!lst)
		dt->nav[NAVOBJECTS].child = nav;
	else
	{
		while (lst->sibling)
			lst = lst->sibling;
		lst->sibling = nav;
	}
}

static void	link_nodes(t_nav *nav, t_obj *obj, t_data *dt)
{
	nav->type = NAVOBJ;
	nav->cont.obj = obj;
	nav->shows = 0;
	nav->current_graphic = NULL;
	nav->select_graphic = NULL;
	nav->default_graphic = NULL;
	nav->alternative_graphic = NULL;
	nav->focus_graphic = NULL;
	nav->tl.x = 0;
	nav->tl.y = 0;
	nav->br.x = 0;
	nav->br.y = 0;
	nav->act = NULL;
	nav->scr = NULL;
	nav->parent = &dt->nav[NAVOBJECTS];
	nav->sibling = NULL;
	nav->active = SET;
	nav->image_lock = UNSET;
	nav->visibility_lock = UNSET;
	link_nodes_2(nav, dt);
}

static int	redirect(t_nav *nav, t_obj *obj, t_data *dt)
{
	if (obj->type == SPHERE && nav_sphere(nav, obj, dt))
		return (FAILURE);
	else if (obj->type == PLANE && nav_plane(nav, obj, dt))
		return (FAILURE);
	else if (obj->type == CYL && nav_cyl(nav, obj, dt))
		return (FAILURE);
	else if (obj->type == CONE && nav_cone(nav, obj, dt))
		return (FAILURE);
	return (SUCCESS);
}

int	nav_obj(t_data *dt)
{
	t_nav	*nav;
	t_obj	*obj;
	int		nb;

	nb = 0;
	set_nav(dt->nav, NAVOBJECTS, "OBJECTS",
		nav_dir(NAVOBJECTS, NAVLIGHTS, NAVDEF, DO_NOT_LINK));
	obj = dt->scene->obj;
	while (obj)
	{
		nav = malloc(sizeof(t_nav));
		if (!nav)
			return (FAILURE);
		ft_bzero(nav, 1 * sizeof(t_nav));
		link_nodes(nav, obj, dt);
		set_next_pos(nav, &dt->nav[NAVOBJECTS], nb++);
		if (redirect(nav, obj, dt))
			return (FAILURE);
		nav->cont_type = obj->type;
		nav->scr = scroll_pane;
		obj = obj->next;
	}
	link_tail(nav, dt);
	return (SUCCESS);
}
