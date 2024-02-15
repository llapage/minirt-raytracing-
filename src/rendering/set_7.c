/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:48:53 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	apply_object_glossiness_to(float *scalar, t_hit *hit, t_ray light_ray)
{
	*scalar = pow(*scalar / (hit->src.len * light_ray.len),
			hit->obj->gloss / 1);
}

void	clear(t_color *color, t_data *dt)
{
	*color = dt->black;
}

void	save_average(t_color color, t_data *dt)
{
	(current_hit(dt))->color = col_div(color, SUPERSAMPLES);
}
