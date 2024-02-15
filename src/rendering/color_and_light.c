/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 16:36:54 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_color	color_and_light(t_hit *hit, t_data *dt)
{
	t_color		color;
	t_unit_rgb	intensity;

	color = surface_color(hit, dt);
	intensity = lights_intensity(hit, dt);
	set_color_intensity(&color, intensity);
	return (color);
}
