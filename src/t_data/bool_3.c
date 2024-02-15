/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:44:47 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 21:50:11 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	was_input_mode(t_data *dt)
{
	if (dt->mode_prev == INPUT)
		return (TRUE);
	else
		return (FALSE);
}

int	was_edit_mode(t_data *dt)
{
	if (dt->mode_prev == EDIT)
		return (TRUE);
	else
		return (FALSE);
}

int	was_default_mode(t_data *dt)
{
	if (dt->mode_prev == DEFAULT)
		return (TRUE);
	else
		return (FALSE);
}

int	object_selected(t_data *dt)
{
	if (dt->curr_obj == NULL)
		return (FALSE);
	else
		return (TRUE);
}

int	active_sub_menu(t_data *dt)
{
	if (dt->nav_loc == NULL)
		return (FALSE);
	else
		return (TRUE);
}
