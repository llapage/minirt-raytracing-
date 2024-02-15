/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_undo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:10:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 11:28:45 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	select_undo(t_nav *nav, t_data *dt)
{
	(void)nav;
	restore_state(dt);
	save_current_hits(dt);
	default_mode(dt);
	object_unselection(dt);
	display_screen_image(dt);
}
