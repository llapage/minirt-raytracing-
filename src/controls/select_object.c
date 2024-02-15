/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2023/12/29 00:25:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	do_select(t_obj *obj, t_pixel ptr, t_data *dt);

int	select_object(t_pixel ptr, t_data *dt)
{
	t_obj	*obj;

	obj = object_under_pointer(ptr, dt);
	if (is_unselected_object(obj, dt))
	{
		do_select(obj, ptr, dt);
		return (1);
	}
	return (0);
}

static void	do_select(t_obj *obj, t_pixel ptr, t_data *dt)
{
	save_click_location(ptr, dt);
	reset_movement(dt);
	grab_object(dt);
	object_selection(obj, dt);
	display_screen_image(dt);
}
