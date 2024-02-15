/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visibility_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 23:09:55 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	set_visible_item(t_nav *nav)
{
	nav->shows = 1;
}

static void	hide_siblings(t_nav *sib, t_nav *nav)
{
	hide_item(sib);
	if (sib->sibling != nav)
		hide_siblings(sib->sibling, nav);
}

void	hide_this_generation(t_nav *nav)
{
	hide_siblings(nav, nav);
}

void	set_visible_siblings(t_nav *sib, t_nav *nav, t_data *dt)
{
	if (sib == nav)
		return ;
	if (drop_down_limit_reached(sib, dt) == FALSE)
		set_visible_item(sib);
	set_visible_siblings(sib->sibling, nav, dt);
}

void	set_visible_children(t_nav *nav, t_data *dt)
{
	t_nav	*drop_down_top;

	if (is_drop_down_parent(nav))
	{
		drop_down_top = get_top_element(nav->child);
		set_visible_this_generation(drop_down_top, dt);
	}
}
