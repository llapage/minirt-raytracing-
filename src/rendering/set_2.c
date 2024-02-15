/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 19:50:43 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	save_current_hits(t_data *dt)
{
	save_state(&dt->hits, HTS, dt);
}

void	link_object_color(t_hit *hit)
{
	hit->color = hit->obj->color;
}

void	initialise_hit(t_hit *hit, t_data *dt)
{
	hit->obj = NULL;
	hit->dist = FLT_MAX;
	hit->color = dt->bgc;
}
