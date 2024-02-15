/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/09 07:59:13 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	release_button(int keycode, t_pixel pointer_location, t_data *dt)
{
	if (keycode == LEFT_BUTTON)
		left_release(pointer_location, dt);
	else if (keycode == RIGHT_BUTTON)
		right_release(pointer_location, dt);
}
