/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:58:18 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	display_enter_to_render_string(t_data *dt)
{
	show_str(dt, "Press enter to render",
		pix_l(S_WIDTH / 2 - 60, S_HEIGHT - 20), GREY);
}

static void	drop_translate(t_pixel ptr, t_data *dt)
{
	t_hit	*hit;

	hit = hit_under_pointer(dt->click_px, dt);
	obj_translate(ptr, *hit, dt);
}

static void	do_drop_object(t_pixel ptr, t_data *dt)
{
	if (object_moved(dt))
	{
		save_current_object_state(dt);
		drop_translate(ptr, dt);
		edit_mode(dt);
		render(dt);
		display_enter_to_render_string(dt);
		unset_current_object(dt);
	}
	release_object(dt);
}

static void	do_drop_scene(t_pixel ptr, t_data *dt)
{
	calculate_movement(ptr, dt);
	if (object_moved(dt))
	{
		rotate_camera(pix_l(dt->x_diff, dt->y_diff), dt);
		edit_mode(dt);
		render(dt);
		display_enter_to_render_string(dt);
		unset_current_object(dt);
	}
	release_scene(dt);
}

int	drop_object(t_pixel ptr, t_data *dt)
{
	if (grabbed_object(dt))
	{
		do_drop_object(ptr, dt);
		return (1);
	}
	else if (grabbed_scene(dt))
	{
		do_drop_scene(ptr, dt);
		return (1);
	}
	return (0);
}
