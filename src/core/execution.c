/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/09 07:58:57 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	execute_button_press(t_data *dt)
{
	int		keycode;
	t_pixel	pointer_location;

	if (dt->loop.button_press == SET)
	{
		keycode = dt->loop.button_press_keycode;
		pointer_location = dt->loop.button_press_pointer_location;
		press_button(keycode, pointer_location, dt);
		clear_instruction(BUTTON_PRESS, dt);
		clear_instruction(MOUSE_MOVE, dt);
		clear_instruction(KEY_PRESS, dt);
	}
}

void	execute_button_release(t_data *dt)
{
	int		keycode;
	t_pixel	pointer_location;

	if (dt->loop.button_release == SET)
	{
		keycode = dt->loop.button_release_keycode;
		pointer_location = dt->loop.button_release_pointer_location;
		release_button(keycode, pointer_location, dt);
		clear_instruction(BUTTON_RELEASE, dt);
		clear_instruction(MOUSE_MOVE, dt);
		clear_instruction(KEY_PRESS, dt);
	}
}

void	execute_mouse_move(t_data *dt)
{
	t_pixel	pointer_location;

	if (dt->loop.mouse_move == SET)
	{
		pointer_location = dt->loop.mouse_move_pointer_location;
		move_mouse(pointer_location, dt);
		clear_instruction(MOUSE_MOVE, dt);
		clear_instruction(KEY_PRESS, dt);
	}
}

void	execute_key_press(t_data *dt)
{
	int	keycode;

	if (dt->loop.key_press == SET)
	{
		keycode = dt->loop.key_press_keycode;
		press_key(keycode, dt);
		clear_instruction(KEY_PRESS, dt);
	}
}
