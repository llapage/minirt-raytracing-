/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:49:30 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 14:21:28 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if __APPLE__

enum {
	SCROLL_DOWN_BUTTON = 4,
	SCROLL_UP_BUTTON = 5,
	RIGHT_BUTTON = 2,
	LEFT_BUTTON = 1,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	Q_KEY = 12,
	E_KEY = 14,
	I_KEY = 34,
	J_KEY = 38,
	K_KEY = 40,
	L_KEY = 37,
	X_KEY = 7,
	Y_KEY = 16,
	Z_KEY = 6,
	ONE_KEY = 83,
	SIX_KEY = 88,
	TWO_KEY = 84,
	DOT_KEY = 65,
	FOUR_KEY = 86,
	FIVE_KEY = 87,
	NINE_KEY = 92,
	ZERO_KEY = 82,
	THREE_KEY = 85,
	SEVEN_KEY = 89,
	EIGHT_KEY = 91,
	MINUS_KEY = 78,
	TAB_KEY = 48,
	NUM_ENTER_KEY = 36,
	ENTER_KEY = 76,
	ESCAPE_KEY = 53,
	BACKSPACE_KEY = 51,
	ARROW_LEFT_KEY = 123,
	ARROW_RIGHT_KEY = 124,
	ARROW_UP_KEY = 126,
	ARROW_DOWN_KEY = 125,
};

# elif __linux__

enum {
	SCROLL_DOWN_BUTTON = 4,
	SCROLL_UP_BUTTON = 5,
	RIGHT_BUTTON = 3,
	LEFT_BUTTON = 1,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	Q_KEY = 113,
	E_KEY = 101,
	I_KEY = 105,
	J_KEY = 106,
	K_KEY = 107,
	L_KEY = 108,
	X_KEY = 120,
	Y_KEY = 121,
	Z_KEY = 122,
	ONE_KEY = 49,
	SIX_KEY = 54,
	TWO_KEY = 50,
	DOT_KEY = 46,
	FOUR_KEY = 52,
	FIVE_KEY = 53,
	NINE_KEY = 57,
	ZERO_KEY = 48,
	THREE_KEY = 51,
	SEVEN_KEY = 55,
	EIGHT_KEY = 56,
	MINUS_KEY = 45,
	TAB_KEY = 65289,
	ENTER_KEY = 65293,
	ESCAPE_KEY = 65307,
	BACKSPACE_KEY = 65288,
	ARROW_LEFT_KEY = 65361,
	ARROW_RIGHT_KEY = 65363,
	ARROW_UP_KEY = 65362,
	ARROW_DOWN_KEY = 65364,
};

# endif

#endif
