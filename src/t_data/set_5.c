/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:53:26 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	request_instruction(t_loop_instruction instruction, t_data *dt)
{
	int	*address;
	int	return_value;

	address = loop_instruction_address(instruction, dt);
	if (address && *address == UNSET)
	{
		*address = SET;
		return_value = SUCCESS;
	}
	else
		return_value = FAILURE;
	return (return_value);
}

void	clear_instruction(t_loop_instruction instruction, t_data *dt)
{
	int	*address;

	address = loop_instruction_address(instruction, dt);
	address = loop_instruction_address(instruction, dt);
	if (address)
		*address = UNSET;
}

void	next_object_loop(t_obj **obj, t_data *dt)
{
	next_object(obj);
	if (*obj == NULL)
		*obj = first_object(dt);
}

void	clear_history(t_data *dt)
{
	clear_all_states(&dt->states);
}
