/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/09 07:54:51 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	loop(void *data)
{
	t_data	*dt;

	dt = (t_data *)data;
	execute_button_press(dt);
	execute_button_release(dt);
	execute_key_press(dt);
	execute_mouse_move(dt);
	return (0);
}
