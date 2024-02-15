/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 08:24:20 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	focus_item_parents(t_nav *nav, t_nav *navdef)
{
	if (nav == navdef)
		return ;
	change_graphic(nav, &nav->focus_graphic);
	focus_item_parents(nav->parent, navdef);
}

void	focus_item_and_parents(t_nav *nav, t_nav *navdef)
{
	if (nav == navdef)
		return ;
	focus_item(nav);
	focus_item_parents(nav, navdef);
}

void	focus_item(t_nav *nav)
{
	change_graphic(nav, &nav->focus_graphic);
}
