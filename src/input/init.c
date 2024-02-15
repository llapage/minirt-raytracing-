/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:26:31 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/08 11:58:57 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	save_underlying_item_state(t_nav *nav, t_data *dt)
{
	void	*addr;
	int		nav_type;
	int		item_type;

	addr = NULL;
	nav_type = nav->parent->type;
	if (nav_type == NAVOBJ)
		addr = nav->parent->cont.obj;
	else if (nav_type == NAVLUX)
		addr = nav->parent->cont.lux;
	else if (nav_type == NAVCAM)
		addr = nav->parent->cont.cam;
	item_type = nav->parent->cont_type;
	save_state(addr, item_type, dt);
}

static void	do_save_state(t_nav *nav, t_data *dt)
{
	save_underlying_item_state(nav, dt);
	set_restore_point(dt);
}

static void	set_visible_input_dialog(t_nav *nav, t_data *dt)
{
	t_nav	*parameter;
	t_nav	*infield;
	int		nb_parameters;

	nb_parameters = 1;
	parameter = nav->child->sibling;
	while (parameter != nav->child)
	{
		nb_parameters++;
		parameter = parameter->sibling;
	}
	infield = &dt->nav[INFIELD_1];
	while (nb_parameters-- > 0)
	{
		set_visible_item(infield);
		infield = infield->sibling;
	}
	set_visible_item(&dt->nav[NAVCONFIRM]);
	set_visible_item(&dt->nav[NAVCANCEL]);
	nav->gp = pix_l(S_WIDTH / 2 - 75, S_HEIGHT / 2 - 106);
	set_visible_item(nav);
}

static void	set_visibility_and_locks(t_nav *nav, t_data *dt)
{
	reset_widgets(dt);
	set_visible_input_dialog(nav, dt);
	lock_visibility_lock_image_and_set_inactive_all(dt);
	set_active_unlock_image_this_generation(nav->child->child);
}

void	input_mode_init(t_nav *nav, t_data *dt)
{
	set_new_mode(INPUT, dt);
	input_dialog_link_item(nav, dt);
	do_save_state(nav, dt);
	dt->cursor_pos = 0;
	set_visibility_and_locks(nav, dt);
	repush_input_dialog_strings_and_display_screen_image(dt);
}
