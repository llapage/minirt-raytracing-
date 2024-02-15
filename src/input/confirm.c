/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:23:18 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:50:58 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	do_set_new_mode(t_data *dt)
{
	if (dt->qlt == LOWRES)
		set_new_mode(EDIT, dt);
	else
		set_new_mode(DEFAULT, dt);
}

void	confirm_input(t_nav *nav, t_data *dt)
{
	(void)nav;
	do_set_new_mode(dt);
	clear_restore_point(dt);
	re_show_menu(nav, dt);
}
