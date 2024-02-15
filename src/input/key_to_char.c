/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:07:57 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:59:02 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static char	key_to_char_2(int keycode)
{
	if (keycode == MINUS_KEY)
		return ('-');
	else if (keycode == ENTER_KEY)
		return ('\n');
	else if (keycode == ESCAPE_KEY)
		return (ASCII_ESC);
	else if (keycode == BACKSPACE_KEY)
		return ('\r');
	return (-1);
}

char	key_to_char(int keycode)
{
	if (keycode == ZERO_KEY)
		return ('0');
	else if (keycode == ONE_KEY)
		return ('1');
	else if (keycode == TWO_KEY)
		return ('2');
	else if (keycode == THREE_KEY)
		return ('3');
	else if (keycode == FOUR_KEY)
		return ('4');
	else if (keycode == FIVE_KEY)
		return ('5');
	else if (keycode == SIX_KEY)
		return ('6');
	else if (keycode == SEVEN_KEY)
		return ('7');
	else if (keycode == EIGHT_KEY)
		return ('8');
	else if (keycode == NINE_KEY)
		return ('9');
	else if (keycode == DOT_KEY)
		return ('.');
	else
		return (key_to_char_2(keycode));
}
