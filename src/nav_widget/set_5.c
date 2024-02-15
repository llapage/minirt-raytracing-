/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:43:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	press_item(t_nav *nav)
{
	change_graphic(nav, &nav->select_graphic);
}

void	reset_item(t_nav *nav)
{
	change_graphic(nav, &nav->default_graphic);
}

void	press_item_and_focus_parents(t_nav *nav, t_nav *navdef)
{
	press_item(nav);
	focus_item_and_parents(nav->parent, navdef);
}

void	change_graphic(t_nav *nav, t_graphic **graphic)
{
	if (image_locked(nav) == UNSET)
		nav->current_graphic = graphic;
}
