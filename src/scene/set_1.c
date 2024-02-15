/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:40:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 16:18:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

void	next_object(t_obj **obj)
{
	if (*obj != NULL)
		*obj = (*obj)->next;
}

void	next_light(t_lux **light)
{
	if (*light != NULL)
		*light = (*light)->next;
}

void	uint_wrap(unsigned int *address, unsigned int min, unsigned int max)
{
	if (*address < min)
		*address = min;
	else if (*address > max)
		*address = max;
}

void	float_wrap(float *address, float min, float max)
{
	if (*address < min)
		*address = min;
	else if (*address > max)
		*address = max;
}
