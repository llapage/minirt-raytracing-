/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 02:11:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

void	restore_state(t_data *dt)
{
	t_state	*st;

	st = dt->states;
	while (st)
		st = undo_state(dt);
}
