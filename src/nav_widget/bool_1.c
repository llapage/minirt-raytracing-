/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:04 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 23:38:52 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

int	is_focused(t_nav *nav)
{
	if (nav && nav->current_graphic == &nav->focus_graphic)
		return (1);
	return (0);
}

int	is_pressed(t_nav *nav)
{
	if (nav && nav->current_graphic == &nav->select_graphic)
		return (1);
	return (0);
}

int	is_default(t_nav *nav)
{
	if (nav && nav->current_graphic == &nav->default_graphic)
		return (1);
	return (0);
}

int	is_alternative(t_nav *nav)
{
	if (nav && nav->current_graphic == &nav->alternative_graphic)
		return (1);
	return (0);
}

int	is_visible(t_nav *nav)
{
	if (nav && nav->shows)
		return (1);
	return (0);
}
