/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:06:15 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:58:33 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

int	button_press_hook(int keycode, int x, int y, t_data *dt)
{
	if (request_instruction(BUTTON_PRESS, dt) == SUCCESS)
	{
		dt->loop.button_press_keycode = keycode;
		dt->loop.button_press_pointer_location = pix_l(x, y);
	}
	return (SUCCESS);
}

int	button_release_hook(int keycode, int x, int y, t_data *dt)
{
	if (request_instruction(BUTTON_RELEASE, dt) == SUCCESS)
	{
		dt->loop.button_release_keycode = keycode;
		dt->loop.button_release_pointer_location = pix_l(x, y);
	}
	return (SUCCESS);
}

int	key_press_hook(int keycode, t_data *dt)
{
	if (request_instruction(KEY_PRESS, dt) == SUCCESS)
		dt->loop.key_press_keycode = keycode;
	return (SUCCESS);
}

int	mouse_move_hook(int x, int y, t_data *dt)
{
	if (request_instruction(MOUSE_MOVE, dt) == SUCCESS)
		dt->loop.mouse_move_pointer_location = pix_l(x, y);
	return (SUCCESS);
}
