/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 14:47:01 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_hit	*current_hit(t_data *dt)
{
	return (&dt->hits[dt->px.y * S_WIDTH + dt->px.x]);
}

t_ray	ray_from_focal_point_to_viewport_point(t_data *dt)
{
	t_ray	ray;

	ray = ray_between(dt->vp->cam, px_to_vp(dt->px, dt));
	ray.type = PRIMARY_RAY;
	return (ray);
}

t_lux	*first_lux(t_data *dt)
{
	return (dt->scene->lux);
}

t_unit_rgb	rgb_intensity_of(t_lux *lux)
{
	t_unit_rgb	rgb_intensity;

	rgb_intensity.red = ((float)lux->color.red / 255.0) * lux->bright;
	rgb_intensity.green = ((float)lux->color.green / 255.0) * lux->bright;
	rgb_intensity.blue = ((float)lux->color.blue / 255.0) * lux->bright;
	return (rgb_intensity);
}

t_ray	from_the_object_towards_the_light(t_hit *hit, t_lux *lux)
{
	t_ray	ray;

	if (lux->type == SPOT)
		ray = ray_between(hit->vtx, lux->src.spot->pos);
	else
		ray = new_ray(hit->vtx, vec_inv(lux->src.dir->dir));
	ray.type = SHADOW_RAY;
	return (ray);
}
