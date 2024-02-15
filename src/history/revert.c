/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 02:14:49 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

void	revert_to_restore_point(t_data *dt)
{
	if (dt->states == NULL
		|| dt->restore_point == NULL)
		return ;
	while (at_restore_point(dt) == FALSE)
		undo_state(dt);
}
