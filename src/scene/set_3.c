/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 16:21:23 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	range_wrap_light_commons(t_lux *light)
{
	uint_wrap(&light->color.red, 0, 255);
	uint_wrap(&light->color.green, 0, 255);
	uint_wrap(&light->color.blue, 0, 255);
	float_wrap(&light->bright, 0.0, 1.0);
}

void	range_wrap_dir(t_d_light *dir)
{
	float_wrap(&dir->dir.x, -1.0, 1.0);
	float_wrap(&dir->dir.y, -1.0, 1.0);
	float_wrap(&dir->dir.z, -1.0, 1.0);
}
