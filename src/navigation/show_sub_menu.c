/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_sub_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2023/12/27 22:08:39 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static t_nav	*obj_to_nav(t_obj *obj, t_data *dt)
{
	t_nav	*nav;

	nav = dt->nav[NAVOBJECTS].child;
	while (nav->cont.obj != obj)
		nav = nav->sibling;
	return (nav);
}

static void	positions(t_nav *nav, t_nav *sib, t_pixel ptr, int i)
{
	nav->tl = pix_l(ptr.x, ptr.y + i * 40);
	nav->br = pix_l(nav->tl.x + 150, nav->tl.y + 40);
	nav->gp = nav->tl;
	set_visible_item(nav);
	if (nav->sibling != sib)
		positions(nav->sibling, sib, ptr, i + 1);
}

static void	visibility_and_lock_mask(t_nav *sub_menu, t_data *dt)
{
	widget_loop(sub_menu, dt);
	set_visible_this_generation(sub_menu, dt);
	lock_visibility_lock_image_and_set_inactive_all(dt);
	set_active_unlock_image_this_generation(sub_menu);
}

static void	do_show_sub_menu(t_obj *obj, t_pixel ptr, t_data *dt)
{
	t_nav	*nav;
	t_nav	*sub_menu;

	nav = obj_to_nav(obj, dt);
	sub_menu = nav->child;
	dt->nav_loc = sub_menu;
	object_selection(obj, dt);
	positions(sub_menu, sub_menu, ptr, 0);
	visibility_and_lock_mask(sub_menu, dt);
	display_screen_image(dt);
}

void	show_sub_menu(t_pixel ptr, t_data *dt)
{
	t_obj	*obj;
	t_nav	*nav;

	obj = object_under_pointer(ptr, dt);
	nav = nav_under_pointer(ptr, dt);
	if (obj != NULL
		&& nav == NULL)
		do_show_sub_menu(obj, ptr, dt);
}
