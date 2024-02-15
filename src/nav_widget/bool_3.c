/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:04 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 23:22:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

int	is_float(t_nav *nav)
{
	if (nav && (nav->type == NAVFLT 
			|| nav->type == NAV3FLT))
		return (1);
	return (0);
}

int	is_infield(t_nav *nav, t_data *dt)
{
	if (nav && (nav == &dt->nav[INFIELD_1]
			|| nav == &dt->nav[INFIELD_2]
			|| nav == &dt->nav[INFIELD_3]))
		return (1);
	return (0);
}

int	is_input_button(t_nav *nav, t_data *dt)
{
	if (nav && (nav == &dt->nav[NAVCONFIRM]
			|| nav == &dt->nav[NAVCANCEL]))
		return (1);
	return (0);
}

int	is_input_dialog(t_nav *nav, t_data *dt)
{
	if (is_infield(nav, dt) || is_input_button(nav, dt))
		return (1);
	return (0);
}

int	is_main_menu(t_nav *nav, t_data *dt)
{
	if (nav && nav->parent == &dt->nav[NAVDEF])
		return (1);
	return (0);
}
