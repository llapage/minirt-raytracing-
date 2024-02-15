/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:49:37 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	save_click_location(t_pixel ptr, t_data *dt)
{
	dt->click_px = pix_l(ptr.x, ptr.y);
}

void	reset_movement(t_data *dt)
{
	dt->x_diff = 0;
	dt->y_diff = 0;
}

void	calculate_movement(t_pixel ptr, t_data *dt)
{
	dt->x_diff = ptr.x - dt->click_px.x;
	dt->y_diff = dt->click_px.y - ptr.y;
}

void	set_first_line(t_data *dt)
{
	dt->px.y = 0;
}

void	set_first_pixel(t_data *dt)
{
	dt->px.x = 0;
}
