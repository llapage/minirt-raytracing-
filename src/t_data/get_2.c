/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:53:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:46:46 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	*current_shape(t_data *dt)
{
	t_obj	*current_object;
	int		object_type;
	void	*current_shape;

	current_object = dt->curr_obj;
	object_type = current_object->type;
	current_shape = NULL;
	if (object_type == SPHERE)
		current_shape = current_object->shape.sphere;
	else if (object_type == CYL)
		current_shape = current_object->shape.cyl;
	else if (object_type == PLANE)
		current_shape = current_object->shape.plane;
	else if (object_type == CONE)
		current_shape = current_object->shape.cone;
	return (current_shape);
}
