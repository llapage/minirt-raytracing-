/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:06:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	drop_down_positions(t_nav *nav, t_nav *sib, t_pixel ptr, int i)
{
	nav->tl = pix_l(ptr.x, ptr.y + i * 40);
	nav->br = pix_l(nav->tl.x + 150, nav->tl.y + 40);
	nav->gp = nav->tl;
	nav->shows = 0;
	if (nav->sibling != sib)
		drop_down_positions(nav->sibling, sib, ptr, i + 1); 
}

static void	reset_position(t_nav *sub_menu)
{
	t_pixel	gp;
	t_pixel	parent_gp;

	parent_gp = sub_menu->parent->gp;
	gp = pix_l(parent_gp.x + 150, parent_gp.y);
	drop_down_positions(sub_menu, sub_menu, gp, 0);
}

void	unset_sub_menu(t_data *dt)
{
	t_nav	*sub_menu;

	sub_menu = dt->nav_loc;
	reset_position(sub_menu);
	unlock_visibility_unlock_image_and_set_active_all(dt);
	lock_visibility_this_generation(&dt->nav[NAVRENDER]);
	dt->nav_loc = NULL;
}

void	put_menu(t_data *dt)
{
	put_graphic_named("menu_bg", pix_l(S_WIDTH / 2 - 340, 0),
		dt->screen_image->image, dt);
	put_if_visible_all(dt, dt->screen_image->image);
	put_color_labels(dt, dt->screen_image->image);
}
