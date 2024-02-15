/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:50:44 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	do_revert_state(t_nav *nav, t_data *dt)
{
	(void)nav;
	if (no_changes_were_made(dt) == TRUE)
		clear_restore_point(dt);
	else
	{
		revert_to_and_clear_restore_point(dt);
		render(dt);
	}
}

void	cancel_input(t_nav *nav, t_data *dt)
{
	revert_mode(dt);
	do_revert_state(nav, dt);
	re_show_menu(nav, dt);
}
