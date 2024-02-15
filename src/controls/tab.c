/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:05:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 20:07:29 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	press_tab(t_data *dt)
{
	t_obj	*obj;

	obj = current_object(dt);
	next_object_loop(&obj, dt);
	object_selection(obj, dt);
	display_screen_image(dt);
}
