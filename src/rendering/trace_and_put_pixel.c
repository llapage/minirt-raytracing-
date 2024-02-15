/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_and_put_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:16:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_hit	*trace_pixel(t_data *dt);

void	trace_and_put_pixel(t_data *dt)
{
	t_hit	*hit;

	hit = trace_pixel(dt);
	put_color(hit, dt);
}

static t_hit	*trace_pixel(t_data *dt)
{
	set_viewport_intersection_point(dt);
	if (rendering_a_stub(dt))
		return (simple_trace(dt));
	else if (is_set(dt->anti_aliasing_switch))
		return (detail_trace(dt));
	else
		return (standard_trace(dt));
}
