/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:55:13 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:33:41 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_tail(t_nav *nav, t_data *dt)
{
	nav = (dt->nav[NAVLIGHTS]).child;
	while (nav->sibling)
		nav = nav->sibling;
	nav->sibling = (dt->nav[NAVLIGHTS]).child;
}

static void	link_nodes(t_nav *nav, t_lux *lux, t_data *dt)
{
	nav->type = NAVLUX;
	nav->shows = 0;
	nav->cont.lux = lux;
	nav->current_graphic = NULL;
	nav->default_graphic = NULL;
	nav->select_graphic = NULL;
	nav->focus_graphic = NULL;
	nav->alternative_graphic = NULL;
	nav->tl.x = 0;
	nav->tl.y = 0;
	nav->br.x = 0;
	nav->br.y = 0;
	nav->act = NULL;
	nav->scr = NULL;
	nav->parent = &dt->nav[2];
	nav->sibling = NULL;
	nav->active = SET;
	nav->image_lock = UNSET;
	nav->visibility_lock = UNSET;
	if ((dt->nav[NAVLIGHTS]).child)
		nav->sibling = (dt->nav[2]).child;
	(dt->nav[NAVLIGHTS]).child = nav;
}

static int	redirect(t_nav *nav, t_lux *lux, t_data *dt)
{
	if (lux->type == AMBIENT
		&& nav_a_light(nav, lux, dt))
		return (FAILURE);
	else if (lux->type == SPOT
		&& nav_s_light(nav, lux, dt))
		return (FAILURE);
	else if (lux->type == DIRECTIONAL
		&& nav_d_light(nav, lux, dt))
		return (FAILURE);
	return (SUCCESS);
}

int	nav_light(t_data *dt)
{
	t_nav	*nav;
	t_lux	*lux;
	int		nb;

	nb = 0;
	set_nav(dt->nav, NAVLIGHTS, "LIGHTS",
		nav_dir(NAVLIGHTS, NAVCAM, NAVDEF, DO_NOT_LINK));
	lux = dt->scene->lux;
	while (lux)
	{
		nav = malloc(sizeof(t_nav));
		if (!nav)
			return (FAILURE);
		ft_bzero(nav, 1 * sizeof(t_nav));
		link_nodes(nav, lux, dt);
		set_next_pos(nav, &dt->nav[NAVLIGHTS], nb++);
		if (redirect(nav, lux, dt))
			return (FAILURE);
		nav->cont_type = lux->type;
		nav->scr = scroll_pane;
		lux = lux->next;
	}
	link_tail(nav, dt);
	return (SUCCESS);
}
