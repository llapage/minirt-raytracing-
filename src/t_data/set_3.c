/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:50:26 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	set_next_super_line(t_data *dt)
{
	(dt->sub_line)++;
}

int	set_current_object(t_obj *obj, t_data *dt)
{
	if (obj != NULL)
	{
		dt->curr_obj = obj;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	unset_current_object(t_data *dt)
{
	dt->curr_obj = NULL;
}

void	grab_object(t_data *dt)
{
	dt->grab = SET;
}

void	release_object(t_data *dt)
{
	dt->grab = UNSET;
}
