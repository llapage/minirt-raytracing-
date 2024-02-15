/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:06:15 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:43:12 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	do_move_mouse(t_pixel ptr, t_data *dt)
{
	if (focus_widget(ptr, dt)
		|| display_move_info(ptr, dt))
		return ;
}

void	move_mouse(t_pixel ptr, t_data *dt)
{
	dt->ptr = ptr;
	if (out_of_bounds(dt->ptr) == FALSE)
		do_move_mouse(dt->ptr, dt);
}
