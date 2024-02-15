/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:38:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	set_active_item(t_nav *nav)
{
	nav->active = SET;
}

void	set_inactive_item(t_nav *nav)
{
	nav->active = UNSET;
}

static void	set_active_unlock_image_siblings(t_nav *nav, t_nav *sib)
{
	set_active_item(nav);
	unlock_image_item(nav);
	if (nav->sibling != sib)
		set_active_unlock_image_siblings(nav->sibling, sib);
}

void	set_active_unlock_image_this_generation(t_nav *nav)
{
	set_active_unlock_image_siblings(nav, nav);
}
