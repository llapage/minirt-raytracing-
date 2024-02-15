/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:04:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 20:24:59 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	set_init_continued(t_data *dt)
{
	dt->nav[NAVRETURN].act = select_undo;
	dt->nav[NAVRENDER].act = select_render;
	dt->nav[NAVCONFIRM].act = confirm_input;
	dt->nav[NAVCANCEL].act = cancel_input;
	dt->nav[NAVEXIT].act = shut_down;
	dt->nav[NAVEXPORT].act = export_out;
	dt->nav[INFIELD_1].act = start_input;
	dt->nav[INFIELD_2].act = start_input;
	dt->nav[INFIELD_3].act = start_input;
}

static void	set_init(t_data *dt)
{
	set_nav(dt->nav, NAVDEF, "DEFAULT", 
		nav_dir(NAVDEF, NAVRENDER, DO_NOT_LINK, DO_NOT_LINK));
	set_nav(dt->nav, NAVRENDER, "RENDER",
		nav_dir(NAVRENDER, NAVRETURN, NAVDEF, DO_NOT_LINK));
	set_nav(dt->nav, NAVRETURN, "UNDO", 
		nav_dir(NAVRETURN, NAVEXPORT, NAVDEF, DO_NOT_LINK));
	set_nav(dt->nav, NAVEXPORT, "EXPORT", 
		nav_dir(NAVEXPORT, NAVOBJECTS, NAVDEF, DO_NOT_LINK));
	set_nav(dt->nav, NAVEXIT, "EXIT", 
		nav_dir(NAVEXIT, NAVRENDER, NAVDEF, DO_NOT_LINK));
	set_nav(dt->nav, INFIELD_1, "INBOX 1", 
		nav_dir(INFIELD_1, INFIELD_2, DO_NOT_LINK, DO_NOT_LINK));
	set_nav(dt->nav, INFIELD_2, "INBOX 2",
		nav_dir(INFIELD_2, INFIELD_3, DO_NOT_LINK, DO_NOT_LINK));
	set_nav(dt->nav, INFIELD_3, "INBOX 3", 
		nav_dir(INFIELD_3, NAVCONFIRM, DO_NOT_LINK, DO_NOT_LINK));
	set_nav(dt->nav, NAVCONFIRM, "CONFIRM", 
		nav_dir(NAVCONFIRM, NAVCANCEL, DO_NOT_LINK, DO_NOT_LINK));
	set_nav(dt->nav, NAVCANCEL, "CANCEL", 
		nav_dir(NAVCANCEL, INFIELD_1, DO_NOT_LINK, DO_NOT_LINK));
	set_init_continued(dt);
}

int	nav_setup(t_data *dt)
{
	set_init(dt);
	set_pos(dt->nav);
	nav_cam(dt);
	nav_settings(dt);
	if (nav_light(dt) == FAILURE)
		return (FAILURE);
	if (nav_obj(dt))
		return (FAILURE);
	link_graph(&dt->nav[NAVRENDER], &dt->nav[NAVRENDER], dt);
	return (SUCCESS);
}
