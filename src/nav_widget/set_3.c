/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:26:58 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	unlock_visibility_item(t_nav *nav)
{
	nav->visibility_lock = UNSET;
}

void	unlock_image_item(t_nav *nav)
{
	nav->image_lock = UNSET;
}

static void	unlock_visibility_image_set_active_this_generation_and_down(
			t_nav *nav, t_nav *sib)
{
	unlock_visibility_item(nav);
	unlock_image_item(nav);
	set_active_item(nav);
	if (nav->sibling != sib)
		unlock_visibility_image_set_active_this_generation_and_down(
			nav->sibling, sib);
	if (nav->child)
		unlock_visibility_image_set_active_this_generation_and_down(
			nav->child, nav->child);
}

void	unlock_visibility_unlock_image_and_set_active_all(t_data *dt)
{
	unlock_visibility_image_set_active_this_generation_and_down(
		&dt->nav[NAVRENDER], &dt->nav[NAVRENDER]);
}
