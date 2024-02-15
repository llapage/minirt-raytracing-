/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 16:01:16 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	there_are_super_lines_left(t_data *dt)
{
	if (dt->sub_line < dt->vp->sqrt_supsam)
		return (TRUE);
	else
		return (FALSE);
}

int	there_are_super_pixels_left(t_data *dt)
{
	if (dt->sub_col < dt->vp->sqrt_supsam)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ambient_light(t_lux *lux)
{
	if (lux->type == AMBIENT)
		return (TRUE);
	else
		return (FALSE);
}

int	blocks(t_obj *obj, t_ray light, t_data *dt)
{
	float	distance;

	dt->ray_count++;
	distance = intersect(light, obj, dt->visib);
	if (distance < light.vec.magnitude)
		return (TRUE);
	else
		return (FALSE);
}

int	is_itself(t_obj *obj, t_hit *hit)
{
	if (hit->obj == obj)
		return (TRUE);
	else
		return (FALSE);
}
