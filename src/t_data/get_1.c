/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:53:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:46:32 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

t_obj	*first_object(t_data *dt)
{
	return (dt->scene->obj);
}

t_obj	*current_object(t_data *dt)
{
	return (dt->curr_obj);
}

int	*loop_instruction_address(t_loop_instruction instruction, t_data *dt)
{
	int	*address;

	if (instruction == KEY_PRESS)
		address = &dt->loop.key_press;
	else if (instruction == BUTTON_PRESS)
		address = &dt->loop.button_press;
	else if (instruction == BUTTON_RELEASE)
		address = &dt->loop.button_release;
	else if (instruction == MOUSE_MOVE)
		address = &dt->loop.mouse_move;
	else
		address = NULL;
	return (address);
}

t_obj	*object_under_pointer(t_pixel ptr, t_data *dt)
{
	t_obj	*obj;

	if (out_of_bounds(ptr))
		obj = NULL;
	else
		obj = dt->hits[ptr.y * S_WIDTH + ptr.x].obj;
	return (obj);
}

t_hit	*hit_under_pointer(t_pixel ptr, t_data *dt)
{
	t_hit	*hit;

	if (out_of_bounds(ptr))
		hit = NULL;
	else
		hit = &dt->hits[ptr.y * S_WIDTH + ptr.x];
	return (hit);
}
