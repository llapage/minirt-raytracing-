/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:16 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:26:37 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

t_color	col_mix(t_color a, t_color b, float pts)
{
	t_color	res;
	float	mix;

	if (pts < 0 || pts > 1)
		return (a);
	mix = sqrt((pow((float)a.red, 2) * pts) 
			+ (pow((float)b.red, 2) * (1 - pts)));
	res.red = mix;
	mix = sqrt((pow((float)a.green, 2) * pts) 
			+ (pow((float)b.green, 2) * (1 - pts)));
	res.green = mix;
	mix = sqrt((pow((float)a.blue, 2) * pts) 
			+ (pow((float)b.blue, 2) * (1 - pts)));
	res.blue = mix;
	return (res);
}

t_color	col_add(t_color a, t_color b)
{
	t_color	res;

	res.red = (a.red + b.red) % 256;
	res.green = (a.green + b.green) % 256;
	res.blue = (a.blue + b.blue) % 256;
	return (res);
}

t_color	col_cnt(t_color a, t_color b)
{
	t_color	res;

	res.red = a.red + b.red;
	res.green = a.green + b.green;
	res.blue = a.blue + b.blue;
	return (res);
}

t_color	col_div(t_color a, float b)
{
	t_color	res;

	res.red = a.red / b;
	res.green = a.green / b;
	res.blue = a.blue / b;
	return (res);
}

t_color	get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color	res;

	res.red = red;
	res.green = green;
	res.blue = blue;
	return (res);
}
