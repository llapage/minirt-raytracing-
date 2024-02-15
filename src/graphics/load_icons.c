/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_icons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/24 17:46:07 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static int	load_icons_continued(t_data *dt);

int	load_icons(t_data *dt)
{
	if (new_graphic(&dt->graph, "obj_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "obj_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "obj_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "light_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "light_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "light_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "cam_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "cam_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "cam_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "set_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "set_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "set_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "render_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "render_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "render_ico_sel", 35, 25) == FAILURE)
		return (FAILURE);
	return (load_icons_continued(dt));
}

static int	load_icons_continued(t_data *dt)
{
	if (new_graphic(&dt->graph, "undo_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "undo_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "undo_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "export_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "export_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "export_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "exit_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "exit_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "exit_ico_sel", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "confirm_ico", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "confirm_ico_fcs", 35, 25) == FAILURE
		|| new_graphic(&dt->graph, "confirm_ico_sel", 35, 25) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
