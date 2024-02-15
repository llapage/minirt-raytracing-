/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:30:10 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 15:03:47 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	do_object_selection(t_nav *nav, t_data *dt)
{
	t_obj	*object;

	object = NULL;
	if (nav->parent == &dt->nav[NAVOBJECTS])
		object = nav->cont.obj;
	else if (nav->parent->parent == &dt->nav[NAVOBJECTS])
		object = nav->parent->cont.obj;
	if (object != NULL)
		object_selection(object, dt);
}

static void	refresh(t_nav *nav, t_data *dt)
{
	if (dt->mode != INPUT)
	{
		focus_item_and_parents(nav, &dt->nav[NAVDEF]);
		if (dt->nav_loc == NULL)
			set_visible_this_generation_and_up(nav, dt);
		set_visible_children(nav, dt);
		do_object_selection(nav, dt);
		display_screen_image(dt);
	}
	else if (dt->mode == INPUT)
	{
		focus_item(nav);
		display_screen_image(dt);
	}
}

static int	do_focus(t_nav *nav, t_data *dt)
{
	widget_loop(nav, dt);
	if (nav)
	{
		refresh(nav, dt);
		return (1);
	}
	return (0);
}

int	focus_widget(t_pixel ptr, t_data *dt)
{
	t_nav	*nav;

	nav = nav_under_pointer(ptr, dt);
	if (is_focused(nav) == FALSE && image_locked(nav) == FALSE)
		return (do_focus(nav, dt));
	return (1);
}
