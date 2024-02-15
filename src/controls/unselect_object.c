/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unselect_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2023/12/29 00:27:24 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	do_unselect(t_data *dt);

int	unselect_object(t_data *dt)
{
	if (dt->curr_obj)
	{
		do_unselect(dt);
		return (1);
	}
	return (0);
}

static void	do_unselect(t_data *dt)
{
	object_unselection(dt);
	display_screen_image(dt);
}
