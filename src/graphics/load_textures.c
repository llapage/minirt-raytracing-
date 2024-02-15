/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 21:29:39 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

int	load_textures(t_data *dt)
{
	if (new_graphic(&dt->graph, "earth_erp", 1350, 675) == FAILURE
		|| new_graphic(&dt->graph, "venus_erp", 1280, 640) == FAILURE
		|| new_graphic(&dt->graph, "mars_erp", 1280, 640) == FAILURE
		|| new_graphic(&dt->graph, "sun_erp", 1280, 640) == FAILURE
		|| new_graphic(&dt->graph, "moon_erp", 1350, 675) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
