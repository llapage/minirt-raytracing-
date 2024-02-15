/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:19:31 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

int	load_graphics(t_data *dt)
{
	if (load_icons(dt) == FAILURE
		|| load_menu_items(dt) == FAILURE
		|| load_textures(dt) == FAILURE
		|| load_normal_maps(dt) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
