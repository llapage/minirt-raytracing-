/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:40:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:12:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

int	get_scroll_direction(int keycode)
{
	if (keycode == SCROLL_UP_BUTTON)
		return (1); 
	else if (keycode == SCROLL_DOWN_BUTTON)
		return (-1);
	return (0);
}

void	wrap_unsigned(unsigned int *n, unsigned int limit)
{
	if (*n == limit)
		*n = 0;
	else if (*n > limit)
		*n = limit - 1;
}

static void	reset_pos(t_nav *nav)
{
	nav->gp = nav->tl;
	nav->shows = 0;
}

void	re_show_menu(t_nav *nav, t_data *dt)
{
	clear_screen_strings(dt);
	reset_pos(nav->parent);
	unlock_visibility_unlock_image_and_set_active_all(dt);
	lock_visibility_this_generation(&dt->nav[NAVRENDER]);
	hide_this_generation(&dt->nav[INFIELD_1]);
	display_screen_image(dt);
}
