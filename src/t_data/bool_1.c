/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:44:47 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:59:41 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	is_unselected_object(t_obj *obj, t_data *dt)
{
	if (obj && obj != dt->curr_obj)
		return (TRUE);
	else
		return (FALSE);
}

int	is_selected_object(t_obj *obj, t_data *dt)
{
	if (obj && obj == dt->curr_obj)
		return (TRUE);
	else
		return (FALSE);
}

int	grabbed_object(t_data *dt)
{
	if (dt->grab)
		return (TRUE);
	else
		return (FALSE);
}

int	grabbed_scene(t_data *dt)
{
	if (dt->scene_grab)
	{
		return (TRUE);
	}
	else
		return (FALSE);
}

int	object_moved(t_data *dt)
{
	if (dt->x_diff || dt->y_diff)
		return (TRUE);
	else
		return (FALSE);
}
