/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:58:43 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	press_button(int keycode, t_pixel pointer_location, t_data *dt)
{
	if (out_of_bounds(pointer_location) == FALSE)
	{
		if (keycode == LEFT_BUTTON)
			left_click(pointer_location, dt);
		else if (keycode == SCROLL_DOWN_BUTTON)
			scroll(pointer_location, keycode, dt);
		else if (keycode == SCROLL_UP_BUTTON)
			scroll(pointer_location, keycode, dt);
	}
}
