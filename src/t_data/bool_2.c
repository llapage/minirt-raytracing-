/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:44:47 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:48:55 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	rendering_a_stub(t_data *dt)
{
	if (dt->qlt == LOWRES)
		return (TRUE);
	else
		return (FALSE);
}

int	in_input_mode(t_data *dt)
{
	if (dt->mode == INPUT)
		return (TRUE);
	else
		return (FALSE);
}

int	in_edit_mode(t_data *dt)
{
	if (dt->mode == EDIT)
		return (TRUE);
	else
		return (FALSE);
}

int	in_default_mode(t_data *dt)
{
	if (dt->mode == DEFAULT)
		return (TRUE);
	else
		return (FALSE);
}
