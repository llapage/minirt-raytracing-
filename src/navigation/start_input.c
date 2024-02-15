/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:59:21 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:06:34 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	appearance(t_nav *nav, t_data *dt)
{
	unlock_image_item(&dt->nav[INFIELD_1]);
	unlock_image_item(&dt->nav[INFIELD_2]);
	unlock_image_item(&dt->nav[INFIELD_3]);
	reset_item(&dt->nav[INFIELD_1]);
	reset_item(&dt->nav[INFIELD_2]);
	reset_item(&dt->nav[INFIELD_3]);
	press_item(nav);
	lock_image_item(nav);
}

void	start_input(t_nav *nav, t_data *dt)
{
	if (is_float(nav))
		*nav->cont.float_number = 0;
	else
		*nav->cont.uint_number = 0;
	appearance(nav, dt);
	repush_input_dialog_strings_and_display_screen_image(dt);
}
