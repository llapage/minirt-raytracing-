/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:17:26 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/25 21:20:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

unsigned int	col_bw(unsigned int col)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (col >> 16) & 0xFF;
	g = (col >> 8) & 0xFF;
	b = (col >> 0) & 0xFF;
	return (((fminf(r, fminf(g, b)) + fmaxf(r, fmaxf(g, b))) * 0.5));
}

int	col_lighten(t_color a)
{
	return (conv_col(col_div(col_add(get_color(255, 255, 255), a), 2)));
}

int	col_darken(t_color a)
{
	return (conv_col(col_div(col_add(get_color(0, 0, 0), a), 2)));
}
