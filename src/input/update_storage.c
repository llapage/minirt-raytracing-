/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:07:57 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:54:25 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	update_int_value(t_nav *nav, int value)
{
	if (value == '\r')
		*nav->cont.uint_number /= 10;
	else
	{
		*nav->cont.uint_number *= 10;
		*nav->cont.uint_number += value - '0';
	}
}

void	update_storage(t_nav *nav, char value, t_data *dt)
{
	if (is_float(nav))
	{
		save_state(nav->cont.float_number, FLOAT, dt);
		update_float_value(nav, value, dt);
	}
	else
	{
		save_state(nav->cont.uint_number, UINT, dt);
		update_int_value(nav, value);
	}
}
