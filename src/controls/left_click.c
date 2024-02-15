/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_click.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:58:40 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	do_select_object(t_obj *obj, t_pixel ptr, t_data *dt);
static void	select_scene(t_pixel ptr, t_data *dt);

void	make_selection(t_pixel ptr, t_data *dt)
{
	t_obj	*obj;

	obj = object_under_pointer(ptr, dt);
	if (is_unselected_object(obj, dt))
		do_select_object(obj, ptr, dt);
	else
	{
		unselect_object(dt);
		if (obj == NULL)
			select_scene(ptr, dt);
	}
}

static void	do_select_object(t_obj *obj, t_pixel ptr, t_data *dt)
{
	save_click_location(ptr, dt);
	reset_movement(dt);
	grab_object(dt);
	object_selection(obj, dt);
	display_screen_image(dt);
}

static void	select_scene(t_pixel ptr, t_data *dt)
{
	save_click_location(ptr, dt);
	reset_movement(dt);
	grab_scene(dt);
	display_screen_image(dt);
}

void	left_click(t_pixel ptr, t_data *dt)
{
	if (press_widget(ptr, dt) == 0)
		make_selection(ptr, dt);
}
