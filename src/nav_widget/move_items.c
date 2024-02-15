/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 16:24:46 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	move_item_bottom_and_align_children(t_nav *nav, t_nav *bottom)
{
	move_item_bottom(nav, bottom);
	move_item_adjacent(nav->child, nav);
}

void	move_item_up_set_visibility_and_align_children(t_nav *nav)
{
	move_item_up(nav);
	if (within_drop_down_limit(nav))
		set_visible_item(nav);
	move_item_adjacent(nav->child, nav);
}

void	move_item_down_and_align_children(t_nav *nav)
{
	move_item_down(nav);
	move_item_adjacent(nav->child, nav);
}

void	move_item_top_set_visibility_and_align_children(t_nav *nav)
{
	move_item_top(nav);
	set_visible_item(nav);
	move_item_adjacent(nav->child, nav);
}
