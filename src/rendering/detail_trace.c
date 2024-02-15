/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:15:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void		do_super_trace_and_add_to_color(t_color *color, t_data *dt);
static void		trace_line_and_add_to_color(t_color *color, t_data *dt);
static t_hit	*trace_super_pixel(t_data *dt);

t_hit	*detail_trace(t_data *dt)
{
	t_color	color;

	clear(&color, dt);
	do_super_trace_and_add_to_color(&color, dt);
	save_average(color, dt);
	return (current_hit(dt));
}

static void	do_super_trace_and_add_to_color(t_color *color, t_data *dt)
{
	set_first_super_line(dt);
	while (there_are_super_lines_left(dt))
	{
		trace_line_and_add_to_color(color, dt);
		set_next_super_line(dt);
	}
}

static void	trace_line_and_add_to_color(t_color *color, t_data *dt)
{
	t_hit	*hit;

	set_first_super_pixel(dt);
	while (there_are_super_pixels_left(dt))
	{
		hit = trace_super_pixel(dt);
		add_color(hit, color);
		set_next_super_pixel(dt);
	}
}

static t_hit	*trace_super_pixel(t_data *dt)
{
	t_ray	ray;
	t_hit	*hit;
	int		depth_rays;

	depth_rays = nb_depth_rays(dt);
	ray = ray_from_focal_point_to_super_viewport_point(dt);
	hit = trace(ray, dt, depth_rays);
	return (hit);
}
