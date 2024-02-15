/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:09:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 23:01:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

int	col_cmp(t_color a, t_color b)
{
	if (a.red != b.red
		|| a.green != b.green
		|| a.blue != b.blue)
		return (1);
	return (0);
}

int	conv_col(t_color color)
{
	return (0 | color.red << 16 | color.green << 8 | color.blue);
}

t_color	get_bg_col(void)
{
	t_color	bg;

	bg.red = BG_RED;
	bg.green = BG_GREEN;
	bg.blue = BG_BLUE;
	return (bg);
}

void	print_color(t_color color)
{
	printf("color:\t\tr%d, g%d, b%d\n", color.red, color.green, color.blue);
}

t_color	col_multiply(t_color a, float b)
{
	t_color	res;

	if (b < 0)
		return (a);
	res.red = fmin(255, a.red * b);
	res.green = fmin(255, a.green * b);
	res.blue = fmin(255, a.blue * b);
	return (res);
}
