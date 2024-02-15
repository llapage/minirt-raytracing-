/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_intensity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:54:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_unit_rgb	light_intensity(t_lux *lux, t_hit *hit, t_data *dt);
static float		light_reaching_object_and_viewer(
						t_lux *lux, t_hit *hit, t_data *dt);

t_unit_rgb	lights_intensity(t_hit *hit, t_data *dt)
{
	t_lux		*lux;
	t_unit_rgb	total_intensity;
	t_unit_rgb	current_light_intensity;

	total_intensity = unit_rgb_black();
	lux = first_lux(dt);
	while (lux)
	{
		current_light_intensity = light_intensity(lux, hit, dt);
		total_intensity = add_unit_rgb(total_intensity, 
				current_light_intensity);
		next_lux(&lux);
	}
	return (total_intensity);
}

static t_unit_rgb	light_intensity(t_lux *lux, t_hit *hit, t_data *dt)
{
	t_unit_rgb	intensity;
	float		reflection_ratio;

	intensity = rgb_intensity_of(lux);
	if (!is_ambient_light(lux))
	{
		reflection_ratio = light_reaching_object_and_viewer(lux, hit, dt);
		intensity = multiply_unit_rgb(intensity, reflection_ratio);
	}
	return (intensity);
}

static float	light_reaching_object_and_viewer(
			t_lux *lux, t_hit *hit, t_data *dt)
{
	t_ray	light_ray;

	light_ray = from_the_object_towards_the_light(hit, lux);
	if (is_shadow(light_ray, hit, dt))
		return (0);
	return (reflection(hit, light_ray));
}
