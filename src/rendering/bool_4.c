/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 20:23:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	is_shadow(t_ray light, t_hit *hit, t_data *dt)
{
	t_obj	*obj;

	obj = first_object(dt);
	while (obj && (!blocks(obj, light, dt) || is_itself(obj, hit)))
		next_object(&obj);
	if (obj)
		return (1);
	return (0);
}

int	is_negative_or_insignificant(float f)
{
	if (f < 0.001)
		return (1);
	return (0);
}

int	not_a_glossy_object(t_hit *hit)
{
	if (hit->obj->gloss == 0)
		return (1);
	return (0);
}
