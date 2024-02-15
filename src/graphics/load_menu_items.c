/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 20:06:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static int	load_menu_items_2(t_data *dt);
static int	load_menu_items_3(t_data *dt);
static int	load_menu_items_4(t_data *dt);
static int	load_menu_items_5(t_data *dt);

int	load_menu_items(t_data *dt)
{
	if (new_graphic(&dt->graph, "menu_bg", 680, 40) == FAILURE
		|| new_graphic(&dt->graph, "input_bg", 150, 26) == FAILURE
		|| new_graphic(&dt->graph, "infield", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "infield_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "infield_sel", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "cone_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "cone_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "plane_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "plane_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "cyl_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "cyl_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "sphere_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "sphere_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "ambient_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "ambient_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "spot_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "spot_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "direct_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "direct_im_fcs", 150, 40) == FAILURE)
		return (FAILURE);
	else
		return (load_menu_items_2(dt));
}

static int	load_menu_items_2(t_data *dt)
{
	if (new_graphic(&dt->graph, "fov_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fov_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "bright_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "bright_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "orien_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "orien_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "locat_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "locat_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "color_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "color_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "diam_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "diam_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "gloss_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "gloss_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "height_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "height_im_fcs", 150, 40) == FAILURE)
		return (FAILURE);
	else
		return (load_menu_items_3(dt));
}

static int	load_menu_items_3(t_data *dt)
{
	if (new_graphic(&dt->graph, "fill_earth_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_earth_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_venus_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_venus_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_solid_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_solid_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_checker_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_checker_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_perlin_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_perlin_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_moon_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_moon_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_sun_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_sun_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_mars_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "fill_mars_im_fcs", 150, 40) == FAILURE)
		return (FAILURE);
	else
		return (load_menu_items_4(dt));
}

static int	load_menu_items_4(t_data *dt)
{
	if (new_graphic(&dt->graph, "surf_smooth_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_smooth_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_perlin_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_perlin_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_earth_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_earth_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_moon_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "surf_moon_im_fcs", 150, 40) == FAILURE)
		return (FAILURE);
	else
		return (load_menu_items_5(dt));
}

static int	load_menu_items_5(t_data *dt)
{
	if (new_graphic(&dt->graph, "reflections_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "reflections_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "reflections_im_sel", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "reflections_im_sel_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "anti_aliasing_im", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "anti_aliasing_im_fcs", 150, 40) == FAILURE
		|| new_graphic(&dt->graph, "anti_aliasing_im_sel", 150, 40) == FAILURE
		|| new_graphic(&dt->graph,
			"anti_aliasing_im_sel_fcs", 150, 40) == FAILURE)
		return (FAILURE);
	else
		return (SUCCESS);
}
