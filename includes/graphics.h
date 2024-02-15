/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:53:00 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:35:13 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../dep/libft/libft.h"
# include "t_data.h"
# include "color.h"
# include "defs.h"
# include "image.h"

typedef struct s_graphic
{
	struct s_graphic	*next;
	unsigned int		*pixel_int;
	t_color				*pixel_color;
	char				*title;
	int					height;
	int					width;
	int					size;
}	t_graphic;

int			load_graphics(t_data *dt);
int			load_icons(t_data *dt);
int			load_menu_items(t_data *dt);
int			load_textures(t_data *dt);
int			load_normal_maps(t_data *dt);
int			new_graphic(t_graphic **top, char *file, int width, int height);
int			parse_file(t_graphic *gr);
void		put_graphic(t_graphic *gr, t_pixel tl, t_image *img);

/* ************************************************************************** */
/*                                                                            */
/*  GET functions                                                             */
/*                                                                            */
/* ************************************************************************** */
t_graphic	*get_graphic(t_data *dt, char *title);
t_color		color_at(t_vertex pixel, t_graphic *gr);
t_pixel		to_int_pixel(t_vertex uip, t_graphic *gr);

/* ************************************************************************** */
/*                                                                            */
/*  SET functions                                                             */
/*                                                                            */
/* ************************************************************************** */
void		put_graphic_named(char *title, t_pixel gp, t_image *img,
				t_data *dt);
void		switch_graphics(t_graphic **a, t_graphic **b);

#endif
