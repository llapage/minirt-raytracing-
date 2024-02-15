/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bool_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 19:53:52 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	new_nearest_object(float distance, t_hit *hit)
{
	if (distance < hit->dist)
		return (1);
	return (0);
}

int	there_are_sub_lines_left(int line, int first_line, t_data *dt)
{
	if (line < S_HEIGHT && line < first_line + dt->sub_samples)
		return (1);
	return (0);
}

int	there_are_sub_pixels_left(int col, t_data *dt)
{
	if (col < S_WIDTH && col < dt->px.x + dt->sub_samples)
		return (1);
	return (0);
}

int	there_are_more_sub_pixels(int i, t_data *dt)
{
	if (i < dt->sub_samples)
		return (1);
	return (0);
}

int	ray_hit_object(t_obj *obj, t_data *dt)
{
	if (obj->hit[dt->px.y][dt->px.x])
		return (1);
	return (0);
}
