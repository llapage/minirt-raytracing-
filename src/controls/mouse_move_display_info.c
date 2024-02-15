/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_display_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2023/12/29 22:28:55 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	display_movement(t_pixel ptr, t_data *dt)
{
	set_move_strings(dt);
	display_main_image(dt);
	show_move_strings(ptr, dt);
}

static void	do_display(t_pixel ptr, t_data *dt)
{
	calculate_movement(ptr, dt);
	display_movement(ptr, dt);
}

int	display_move_info(t_pixel ptr, t_data *dt)
{
	if (grabbed_object(dt))
	{
		do_display(ptr, dt);
		return (1);
	}
	return (0);
}
