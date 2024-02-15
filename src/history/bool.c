/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 02:27:03 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

int	no_changes_were_made(t_data *dt)
{
	if (at_restore_point(dt) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

int	at_restore_point(t_data *dt)
{
	if (dt->states != NULL
		&& dt->restore_point != NULL
		&& dt->states == dt->restore_point)
		return (TRUE);
	else
		return (FALSE);
}
