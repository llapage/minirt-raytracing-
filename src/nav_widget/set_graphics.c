/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 11:04:11 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	do_graph_link(t_nav *nav, t_nav_graphics ng, t_data *dt)
{
	nav->default_graphic = get_graphic(dt, ng.def);
	nav->focus_graphic = get_graphic(dt, ng.fcs);
	nav->select_graphic = get_graphic(dt, ng.sel);
	nav->alternative_graphic = get_graphic(dt, ng.alt);
	nav->current_graphic = &nav->default_graphic;
}

void	set_surface_im(t_nav *nav, t_data *dt)
{
	t_nav_graphics	n_g;

	if (*nav->cont.uint_number == SMOOTH_SURFACE)
		n_g = file_names("surf_smooth_im", "surf_smooth_im_fcs", 
				"surf_smooth_im_fcs", NULL);
	else if (*nav->cont.uint_number == PERLIN_SURFACE)
		n_g = file_names("surf_perlin_im", "surf_perlin_im_fcs", 
				"surf_perlin_im_fcs", NULL);
	else if (*nav->cont.uint_number == EARTH_SURFACE)
		n_g = file_names("surf_earth_im", "surf_earth_im_fcs", 
				"surf_earth_im_fcs", NULL);
	else if (*nav->cont.uint_number == MOON_SURFACE)
		n_g = file_names("surf_moon_im", "surf_moon_im_fcs", 
				"surf_moon_im_fcs", NULL);
	else
		n_g = file_names(NULL, NULL, NULL, NULL);
	do_graph_link(nav, n_g, dt);
}

static t_nav_graphics	set_fill_im_continued(t_nav *nav)
{
	t_nav_graphics	n_g;

	if (*nav->cont.uint_number == MOON_FILL)
		n_g = file_names("fill_moon_im", "fill_moon_im_fcs", 
				"fill_moon_im_fcs", NULL);
	else if (*nav->cont.uint_number == SUN_FILL)
		n_g = file_names("fill_sun_im", "fill_sun_im_fcs", 
				"fill_sun_im_fcs", NULL);
	else if (*nav->cont.uint_number == VENUS_FILL)
		n_g = file_names("fill_venus_im", "fill_venus_im_fcs", 
				"fill_venus_im_fcs", NULL);
	else if (*nav->cont.uint_number == MARS_FILL)
		n_g = file_names("fill_mars_im", "fill_mars_im_fcs", 
				"fill_mars_im_fcs", NULL);
	else
		n_g = file_names(NULL, NULL, NULL, NULL);
	return (n_g);
}

void	set_fill_im(t_nav *nav, t_data *dt)
{
	t_nav_graphics	n_g;

	if (*nav->cont.uint_number == SOLID_FILL)
		n_g = file_names("fill_solid_im", "fill_solid_im_fcs", 
				"fill_solid_im_fcs", NULL);
	else if (*nav->cont.uint_number == CHECKER_FILL)
		n_g = file_names("fill_checker_im", "fill_checker_im_fcs", 
				"fill_checker_im_fcs", NULL);
	else if (*nav->cont.uint_number == PERLIN_FILL)
		n_g = file_names("fill_perlin_im", "fill_perlin_im_fcs", 
				"fill_perlin_im_fcs", NULL);
	else if (*nav->cont.uint_number == EARTH_FILL)
		n_g = file_names("fill_earth_im", "fill_earth_im_fcs", 
				"fill_earth_im_fcs", NULL);
	else
		n_g = set_fill_im_continued(nav);
	do_graph_link(nav, n_g, dt);
}
