/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 23:13:17 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static int	redirect_4(t_nav_graphics *n_g, t_nav *nav)
{
	if (!(ft_strcmp("REFLECTIONS", nav->desc)))
		*n_g = file_names("reflections_im", "reflections_im_fcs", 
				"reflections_im_sel", "reflections_im_sel_fcs");
	else if (!(ft_strcmp("ANTI_ALIASING", nav->desc)))
		*n_g = file_names("anti_aliasing_im", "anti_aliasing_im_fcs", 
				"anti_aliasing_im_sel", "anti_aliasing_im_sel_fcs");
	else
		*n_g = file_names("NULL", "NULL", "NULL", NULL);
	return (1);
}

static int	redirect_3(t_nav_graphics *n_g, t_nav *nav)
{
	if (!(ft_strcmp("GLOSS", nav->desc)))
		*n_g = file_names("gloss_im", "gloss_im_fcs", "gloss_im_fcs", NULL);
	else if (!(ft_strcmp("AMBIENT", nav->desc)))
		*n_g = file_names("ambient_im", "ambient_im_fcs", "ambient_im_fcs",
				NULL);
	else if (!(ft_strcmp("SPOT", nav->desc)))
		*n_g = file_names("spot_im", "spot_im_fcs", "spot_im_fcs", NULL);
	else if (!(ft_strcmp("DIRECTIONAL", nav->desc)))
		*n_g = file_names("direct_im", "direct_im_fcs", "direct_im_fcs", NULL);
	else if (!(ft_strcmp("SPHERE", nav->desc)))
		*n_g = file_names("sphere_im", "sphere_im_fcs", "sphere_im_fcs", NULL);
	else if (!(ft_strcmp("PLANE", nav->desc)))
		*n_g = file_names("plane_im", "plane_im_fcs", "plane_im_fcs", NULL);
	else if (!(ft_strcmp("CYLINDER", nav->desc)))
		*n_g = file_names("cyl_im", "cyl_im_fcs", "cyl_im_fcs", NULL);
	else if (!(ft_strcmp("CONE", nav->desc)))
		*n_g = file_names("cone_im", "cone_im_fcs", "come_im_fcs", NULL);
	else if (!redirect_4(n_g, nav))
		return (0);
	return (1);
}

static int	redirect_2(t_nav_graphics *n_g, t_nav *nav)
{
	if (!(ft_strcmp("SETTINGS", nav->desc)))
		*n_g = file_names("set_ico", "set_ico_fcs", "set_ico_sel", NULL);
	else if (!(ft_strcmp("EXIT", nav->desc)))
		*n_g = file_names("exit_ico", "exit_ico_fcs", "exit_ico_sel", NULL);
	else if (!(ft_strcmp("INBOX 1", nav->desc))
		|| !(ft_strcmp("INBOX 2", nav->desc))
		|| !(ft_strcmp("INBOX 3", nav->desc)))
		*n_g = file_names("infield", "infield_fcs", "infield_sel", NULL);
	else if (!(ft_strcmp("CONFIRM", nav->desc)))
		*n_g = file_names("confirm_ico", "confirm_ico_fcs", "confirm_ico_sel", 
				NULL);
	else if (!(ft_strcmp("CANCEL", nav->desc)))
		*n_g = file_names("undo_ico", "undo_ico_fcs", "undo_ico_sel", NULL);
	else if (!(ft_strcmp("ORIENTATION", nav->desc)))
		*n_g = file_names("orien_im", "orien_im_fcs", "orien_im_fcs", NULL);
	else if (!(ft_strcmp("FOV", nav->desc)))
		*n_g = file_names("fov_im", "fov_im_fcs", "fov_im_fcs", NULL);
	else if (!(ft_strcmp("HEIGHT", nav->desc)))
		*n_g = file_names("height_im", "height_im_fcs", "height_im_fcs", NULL);
	else if (!(ft_strcmp("BRIGHTNESS", nav->desc)))
		*n_g = file_names("bright_im", "bright_im_fcs", "bright_im_fcs", NULL);
	else if (!redirect_3(n_g, nav))
		return (0);
	return (1);
}

static void	link_item_graph(t_nav *nav, t_data *dt)
{
	t_nav_graphics	n_g;

	if (!(ft_strcmp("LOCATION", nav->desc)))
		n_g = file_names("locat_im", "locat_im_fcs", "locat_im_fcs", NULL);
	else if (!(ft_strcmp("DIAMETER", nav->desc)))
		n_g = file_names("diam_im", "diam_im_fcs", "diam_im_fcs", NULL);
	else if (!(ft_strcmp("COLOR", nav->desc)))
		n_g = file_names("color_im", "color_im_fcs", "color_im_fcs", NULL);
	else if (!(ft_strcmp("RENDER", nav->desc)))
		n_g = file_names("render_ico", "render_ico_fcs", "render_ico_sel", 
				"render_ico");
	else if (!(ft_strcmp("UNDO", nav->desc)))
		n_g = file_names("undo_ico", "undo_ico_fcs", "undo_ico_sel", NULL);
	else if (!(ft_strcmp("EXPORT", nav->desc)))
		n_g = file_names("export_ico", "export_ico_fcs", "export_ico_sel", 
				NULL);
	else if (!(ft_strcmp("OBJECTS", nav->desc)))
		n_g = file_names("obj_ico", "obj_ico_fcs", "obj_ico_sel", NULL);
	else if (!(ft_strcmp("LIGHTS", nav->desc)))
		n_g = file_names("light_ico", "light_ico_fcs", "light_ico_sel", NULL);
	else if (!(ft_strcmp("CAMERA", nav->desc)))
		n_g = file_names("cam_ico", "cam_ico_fcs", "cam_ico_sel", NULL);
	else if (!(redirect_2(&n_g, nav)))
		return ;
	do_graph_link(nav, n_g, dt);
}

void	link_graph(t_nav *nav, t_nav *sib, t_data *dt)
{
	if (!(ft_strcmp("FILL", nav->desc)))
		set_fill_im(nav, dt);
	else if (!(ft_strcmp("SURFACE", nav->desc)))
		set_surface_im(nav, dt);
	else
		link_item_graph(nav, dt);
	if (nav->child)
		link_graph(nav->child, nav->child, dt);
	if (nav->sibling != sib)
		link_graph(nav->sibling, sib, dt);
}
