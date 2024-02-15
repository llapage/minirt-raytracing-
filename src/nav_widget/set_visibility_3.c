/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visibility_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:50:02 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	hide_item(t_nav *nav)
{
	nav->shows = UNSET;
}

int	try_hide_item(t_nav *nav)
{
	int	return_value;

	if (is_visible(nav) == TRUE
		&& visibility_locked(nav) == UNSET)
	{
		hide_item(nav);
		return_value = CHANGED;
	}
	else
		return_value = UNCHANGED;
	return (return_value);
}

static void	reset_image(t_nav *nav)
{
	nav->current_graphic = &nav->default_graphic;
}

int	try_reset_image(t_nav *nav)
{
	int	return_value;

	if (is_default(nav) == FALSE
		&& image_locked(nav) == UNSET)
	{
		reset_image(nav);
		return_value = CHANGED;
	}
	else
		return_value = UNCHANGED;
	return (return_value);
}
