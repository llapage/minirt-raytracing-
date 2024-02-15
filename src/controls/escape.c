/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:05:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 11:28:18 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	press_escape(t_data *dt)
{
	if (in_input_mode(dt))
	{
		cancel_input(NULL, dt);
		display_screen_image(dt);
	}
	else if (in_edit_mode(dt))
	{
		restore_state(dt);
		save_current_hits(dt);
		revert_mode(dt);
		object_unselection(dt);
		display_screen_image(dt);
	}
	else if (object_selected(dt))
	{
		object_unselection(dt);
		display_screen_image(dt);
	}
	else
		exit_minirt(dt);
}
