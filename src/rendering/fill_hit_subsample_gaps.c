/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hit_subsample_gaps.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:38:34 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 20:30:56 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void		fill_hit_subsample_gaps(t_hit *hit, t_data *dt);
static void	fill_hit_subsample_gaps_line(t_hit *hit, int line, t_data *dt);

void	fill_hit_subsample_gaps(t_hit *hit, t_data *dt)
{
	int	first_line;
	int	line;

	first_line = first_sub_line(dt);
	line = first_line;
	while (there_are_sub_lines_left(line, first_line, dt))
	{
		fill_hit_subsample_gaps_line(hit, line, dt);
		line++;
	}
}

static void	fill_hit_subsample_gaps_line(t_hit *hit, int line, t_data *dt)
{
	int	col;

	col = first_sub_pixel(dt);
	while (there_are_sub_pixels_left(col, dt))
	{
		copy_hit(col, line, hit, dt);
		col++;
	}
}
