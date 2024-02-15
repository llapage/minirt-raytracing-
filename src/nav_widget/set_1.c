/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:25:55 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	lock_visibility_item(t_nav *nav)
{
	nav->visibility_lock = SET;
}

void	lock_image_item(t_nav *nav)
{
	nav->image_lock = SET;
}

static void	lock_visibility_lock_image_set_inactive_this_generation_and_down(
		t_nav *nav, t_nav *sib)
{
	lock_visibility_item(nav);
	lock_image_item(nav);
	set_inactive_item(nav);
	if (nav->sibling != sib)
		lock_visibility_lock_image_set_inactive_this_generation_and_down(
			nav->sibling, sib);
	if (nav->child)
		lock_visibility_lock_image_set_inactive_this_generation_and_down(
			nav->child, nav->child);
}

void	lock_visibility_lock_image_and_set_inactive_all(t_data *dt)
{
	lock_visibility_lock_image_set_inactive_this_generation_and_down(
		&dt->nav[NAVRENDER], &dt->nav[NAVRENDER]);
}
