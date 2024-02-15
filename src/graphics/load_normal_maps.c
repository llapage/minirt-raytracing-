/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_normal_maps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 19:47:04 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

int	load_normal_maps(t_data *dt)
{
	if (new_graphic(&dt->graph, "earth_nm", 1350, 675) == FAILURE
		|| new_graphic(&dt->graph, "moon_nm", 1350, 675) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
