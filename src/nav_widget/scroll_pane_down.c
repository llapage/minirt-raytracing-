/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_pane_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 15:10:03 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	do_scroll_down(t_nav *nav, t_nav *bottom)
{
	if (nav == bottom)
		move_item_top_set_visibility_and_align_children(bottom);
	else
		move_item_down_and_align_children(nav);
}

static void	scroll_siblings_down(t_nav *sib, t_nav *nav, t_nav *bottom)
{
	if (sib == nav)
		return ;
	do_scroll_down(sib, bottom);
	scroll_siblings_down(sib->sibling, nav, bottom);
}

void	scroll_pane_down(t_nav *nav, t_nav *bottom)
{
	do_scroll_down(nav, bottom);
	scroll_siblings_down(nav->sibling, nav, bottom);
}
