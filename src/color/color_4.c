/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:16 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:26:50 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

t_unit_rgb	unit_rgb_black(void)
{
	t_unit_rgb	black;

	black.red = 0;
	black.green = 0;
	black.blue = 0;
	return (black);
}

t_unit_rgb	multiply_unit_rgb(t_unit_rgb a, float b)
{
	t_unit_rgb	res;

	if (b < 0 || b > 1)
		return (a);
	res.red = a.red * b;
	res.green = a.green * b;
	res.blue = a.blue * b;
	return (res);
}

t_unit_rgb	add_unit_rgb(t_unit_rgb a, t_unit_rgb b)
{
	t_unit_rgb	res;

	res.red = fmin(1, a.red + b.red);
	res.green = fmin(1, a.green + b.green);
	res.blue = fmin(1, a.blue + b.blue);
	return (res);
}
