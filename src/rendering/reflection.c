/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:14:02 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static float	toward_source_reflection(t_hit *hit, t_ray light_ray);
static float	toward_viewer_reflection(t_hit *hit, t_ray light_ray);

float	reflection(t_hit *hit, t_ray light_ray)
{
	float	ratio;

	zero(&ratio);
	ratio += toward_source_reflection(hit, light_ray);
	ratio += toward_viewer_reflection(hit, light_ray);
	return (ratio);
}

static float	toward_source_reflection(t_hit *hit, t_ray light_ray)
{
	float	scalar;

	scalar = strenght_of_reflection_back_to_the_light(hit, light_ray);
	if (is_negative_or_insignificant(scalar))
		return (0);
	weaken_scalar_by_the_lights_distance(&scalar, light_ray);
	return (scalar);
}

static float	toward_viewer_reflection(t_hit *hit, t_ray light_ray)
{
	float	scalar;

	scalar = strenght_of_reflection_toward_the_viewer(hit, light_ray);
	if ((not_a_glossy_object(hit)) || is_negative_or_insignificant(scalar))
		return (0);
	apply_object_glossiness_to(&scalar, hit, light_ray);
	return (scalar);
}
