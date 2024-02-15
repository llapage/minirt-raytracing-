/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:07:57 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:53:06 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	do_update(t_nav *nav, float multiplier, float addend)
{
	*nav->cont.float_number *= multiplier;
	*nav->cont.float_number += addend;
}

static void	set_elems(float *multiplier, float *addend,
		int value, t_data *dt)
{
	if (value == '-')
	{
		*multiplier = -1;
		*addend = 0;
	}
	else if (value == '.')
	{
		*multiplier = 1;
		*addend = 0;
		dt->cursor_pos = -1;
	}
	else if (dt->cursor_pos < 0)
	{
		*multiplier = 1;
		*addend = (value - '0') * pow(10.0, dt->cursor_pos);
		(dt->cursor_pos)--;
	}
	else
	{
		*multiplier = 10;
		*addend = (value - '0');
	}
}

static void	set_backslash_elems(float *multiplier, float *addend,
		float nb, t_data *dt)
{
	if (dt->cursor_pos > -2)
	{
		*multiplier = 0.1;
		*addend = -fmod(nb, 10) / 10;
		dt->cursor_pos = 0;
	}
	else
	{
		*multiplier = 1;
		*addend = -fmod((nb * pow(10, - (dt->cursor_pos + 1))), 10) * 
			pow(10, dt->cursor_pos + 1);
		dt->cursor_pos++;
	}
}

void	update_float_value(t_nav *nav, char value, t_data *dt)
{
	float	multiplier;
	float	addend;

	if (value == '\r')
		set_backslash_elems(&multiplier, &addend, *nav->cont.float_number, dt);
	else
		set_elems(&multiplier, &addend, value, dt);
	if (*nav->cont.float_number < 0)
		addend *= -1;
	do_update(nav, multiplier, addend);
}
