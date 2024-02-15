/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:38:49 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:47:13 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
/*
static void	fill_pb_bg(t_image *mut)
{
	int		line;
	int		col;
	int		mid_line;
	int		mid_col;

	mid_line = S_HEIGHT / 2;
	mid_col = S_WIDTH / 2;
	line = 0;
	while (line < 5)
	{
		col = 0;
		while (col < 102)
			my_mlx_pixel_put(mut, col++ + mid_col - 51,
				line + mid_line - 1, DARKGREY);
		line++;
	}
}

static void	fill_bg(t_image *mut)
{
	int		line;
	int		col;

	line = 0;
	while (line < S_HEIGHT)
	{
		col = 0;
		while (col < S_WIDTH)
			my_mlx_pixel_put(mut, col++, line, DARKBLUEMAGENTA);
		line++;
	}
}

void	clear_mut(t_data *dt)
{
	(void)fill_bg;
//	copy_image(dt->screen_image->image, dt->stub_render_image);
	fill_pb_bg(dt->screen_image->image);
}
*/
void	update_progress_bar(t_data *dt)
{
	int	i;
	int	col;
	int	prog;

	prog = dt->px.y * 100 / S_HEIGHT;
	col = S_WIDTH / 2 - 50 + prog;
	i = 0;
	while (i++ < 3)
	{
		my_mlx_pixel_put(dt->screen_image->image, col, 
			S_HEIGHT / 2 - 1, YELLOWGREEN);
		my_mlx_pixel_put(dt->screen_image->image, col, 
			S_HEIGHT / 2, YELLOWGREEN);
		my_mlx_pixel_put(dt->screen_image->image, col, 
			S_HEIGHT / 2 + 1, YELLOWGREEN);
	}
	display_main_image(dt);
}
