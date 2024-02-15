/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bool_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 13:46:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	there_are_lines_left(t_data *dt)
{
	if (dt->px.y < S_HEIGHT - 2 * dt->vp->b_offs)
		return (1);
	return (0);
}

int	there_are_pixels_left(t_data *dt)
{
	if (dt->px.x < S_WIDTH)
		return (1);
	return (0);
}

int	intersects_an_object(t_hit *ht)
{
	if (ht->obj)
		return (1);
	return (0);
}
