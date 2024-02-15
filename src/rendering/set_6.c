/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 22:52:19 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	add_color(t_hit *hit, t_color *color)
{
	*color = col_cnt(*color, hit->color);
}

void	zero(float *f)
{
	*f = 0.0;
}

void	next_lux(t_lux **lux)
{
	*lux = (*lux)->next;
}

void	set_color_intensity(t_color *color, t_unit_rgb intensity)
{
	color->red = color->red * intensity.red;
	color->green = color->green * intensity.green;
	color->blue = color->blue * intensity.blue;
}

void	weaken_scalar_by_the_lights_distance(float *scalar, t_ray light_ray)
{
	*scalar /= light_ray.len;
}
