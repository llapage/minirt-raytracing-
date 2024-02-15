/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:07:57 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:43:36 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static int	valid_input(int value, t_nav *infield, t_data *dt)
{
	if (value < 0
		|| (value == '.' && is_float(infield) == FALSE)
		|| (value == '-' && is_float(infield) == FALSE)
		|| (value == '.' && dt->cursor_pos < 0)
		|| (value != '\r' && dt->cursor_pos < -2))
		return (FALSE);
	return (TRUE);
}

static void	render_and_show(t_data *dt)
{
	input_mode(dt);
	render(dt);
	repush_input_dialog_strings_and_display_screen_image(dt);
}

static void	process_input(int value, t_nav *infield, t_data *dt)
{
	if (value == '\n')
	{
		confirm_input(infield, dt);
	}
	else if (value == ASCII_ESC)
	{
		cancel_input(infield, dt);
	}
	else if (valid_input(value, infield, dt))
	{
		update_storage(infield, value, dt);
		render_and_show(dt);
	}
}

void	user_input(int keycode, t_nav *infield, t_data *dt)
{
	char	value;

	if (infield)
	{
		value = key_to_char(keycode);
		process_input(value, infield, dt);
	}
}
