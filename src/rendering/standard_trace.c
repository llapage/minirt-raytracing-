/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:57:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_hit	*standard_trace(t_data *dt)
{
	t_ray	ray;
	t_hit	*hit;
	int		depth_rays;

	depth_rays = nb_depth_rays(dt);
	ray = ray_from_focal_point_to_viewport_point(dt);
	hit = trace(ray, dt, depth_rays);
	return (hit);
}
