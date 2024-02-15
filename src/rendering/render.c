/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 16:00:26 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void	pre_render(t_data *dt);
void		do_render(t_data *dt);
static void	render_line(t_data *dt);

void	render(t_data *dt)
{
	pre_render(dt);
	do_render(dt);
	display_screen_image(dt);
}

static void	pre_render(t_data *dt)
{
	dt->ray_count = 0;
	if (rendering_a_stub(dt) == FALSE)
	{
		object_unselection(dt);
		save_current_hits(dt);
	}
	else
		clear_stub_images(dt);
	set_vars(dt);
}

void	do_render(t_data *dt)
{
	set_first_line(dt);
	while (there_are_lines_left(dt))
	{
		render_line(dt);
		set_next_line(dt);
	}
}

static void	render_line(t_data *dt)
{
	set_first_pixel(dt);
	if (!rendering_a_stub(dt))
		update_progress_bar(dt);
	while (there_are_pixels_left(dt))
	{
		trace_and_put_pixel(dt);
		set_next_pixel(dt);
	}
}
