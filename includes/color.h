/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:06:38 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 16:51:47 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdio.h>
# include <math.h>
# include "params.h"

# define GREY 6579300
# define YELLOWGREEN 13762360
# define DARKGREY 1184274
# define DARKBLUEMAGENTA 1710619
# define BLACK 0
# define WHITE 16777215

typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_color;

typedef struct s_unit_rgb
{
	float	red;
	float	green;
	float	blue;
}	t_unit_rgb;

unsigned int	col_bw(unsigned int col);
t_color			get_color(unsigned char red,
					unsigned char green, unsigned char blue);
t_color			col_mix(t_color a, t_color b, float pts);
t_color			col_multiply(t_color a, float b);
t_color			col_add(t_color a, t_color b);
t_color			col_cnt(t_color a, t_color b);
t_color			col_div(t_color a, float b);
t_color			get_bg_col(void);
t_unit_rgb		unit_rgb_black(void);
t_unit_rgb		multiply_unit_rgb(t_unit_rgb a, float b);
t_unit_rgb		add_unit_rgb(t_unit_rgb a, t_unit_rgb b);
void			print_color(t_color color);
int				col_cmp(t_color a, t_color b);
int				conv_col(t_color color);
int				col_lighten(t_color a);
int				col_darken(t_color a);

#endif
