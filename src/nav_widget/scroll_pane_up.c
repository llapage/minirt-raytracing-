/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_pane_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 15:11:24 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	do_scroll_up(t_nav *nav, t_nav *bottom)
{
	if (nav == bottom)
		move_item_bottom_and_align_children(bottom->sibling, bottom);
	if (nav != bottom->sibling)
		move_item_up_set_visibility_and_align_children(nav);
}

static void	scroll_siblings_up(t_nav *sib, t_nav *nav, t_nav *bottom)
{
	if (sib == nav)
		return ;
	do_scroll_up(sib, bottom);
	scroll_siblings_up(sib->sibling, nav, bottom);
}

void	scroll_pane_up(t_nav *nav, t_nav *bottom)
{
	do_scroll_up(nav, bottom);
	scroll_siblings_up(nav->sibling, nav, bottom);
}
