/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_move_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2023/12/18 13:02:42 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	show_move_strings(t_pixel ptr, t_data *dt)
{
	show_str(dt, dt->coord_msg[X], pix_l(ptr.x + 10, ptr.y + 30), GREY);
	show_str(dt, dt->coord_msg[Y], pix_l(ptr.x + 10, ptr.y + 45), GREY);
	free(dt->coord_msg[X]);
	free(dt->coord_msg[Y]);
	dt->coord_msg[X] = NULL;
	dt->coord_msg[Y] = NULL;
}
