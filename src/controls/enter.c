/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:05:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 20:32:01 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	press_enter(t_data *dt)
{
	if (in_input_mode(dt))
		confirm_input(NULL, dt);
	else if (active_sub_menu(dt))
	{
		unset_sub_menu(dt);
		display_screen_image(dt);
	}
	else
	{
		widget_loop(NULL, dt);
		if (in_edit_mode(dt))
		{
			default_mode(dt);
			clear_history(dt);
			render(dt);
		}
		display_screen_image(dt);
	}
}
