/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:45:07 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:31:36 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	link_data(t_data *dt)
{
	(dt->nav[18]).cont.uint_number = &dt->reflections_switch;
	(dt->nav[19]).cont.uint_number = &dt->anti_aliasing_switch;
}

static void	link_nodes(t_data *dt)
{
	set_nav(dt->nav, NAVSETTINGS, "SETTINGS", 
		nav_dir(NAVSETTINGS, NAVEXIT, NAVDEF, 18));
	set_nav(dt->nav, NAVINT, "REFLECTIONS", nav_dir(18, 19, NAVSETTINGS, -1));
	set_nav(dt->nav, NAVINT, "ANTI_ALIASING", nav_dir(19, 18, NAVSETTINGS, -1));
}

static void	set_settings_act(t_nav *nav)
{
	nav[18].act = switch_reflections;
	nav[19].act = switch_anti_aliasing;
}

void	nav_settings(t_data *dt)
{
	link_nodes(dt);
	link_data(dt);
	dt->nav[NAVSETTINGS].cont_type = NAVINT;
	set_settings_pos(dt->nav);
	set_settings_act(dt->nav);
}
