/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:18:44 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	select_object_under_current_pointer(t_data *dt)
{
	t_obj	*obj;
	int		return_value;

	obj = object_under_pointer(dt->ptr, dt);
	if (obj == NULL)
		return_value = FAILURE;
	else
	{
		object_selection(obj, dt);
		return_value = SUCCESS;
	}
	return (return_value);
}

void	object_selection(t_obj *obj, t_data *dt)
{
	set_current_object(obj, dt);
	set_render_image_to(&obj->render_image_pointer, dt);
}

void	object_unselection(t_data *dt)
{
	unset_current_object(dt);
	set_render_image_to(&dt->render_image_pointer, dt);
}

void	save_current_object_state(t_data *dt)
{
	if (object_selected(dt) == TRUE)
		save_obj_state(dt->curr_obj, dt);
}
