/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:30:20 by llapage           #+#    #+#             */
/*   Updated: 2023/12/09 18:04:28 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "memory.h"
# include "vector.h"
# include "scene.h"
# include "ftoa.h"
# include "defs.h"
# include "../dep/libft/libft.h"

void		print_vertex(char *desc, t_vertex vtx);
void		print_vector(char *desc, t_vector vec);
void		print_sphere(t_obj *obj, int id);
void		print_plane(t_obj *obj, int id);
void		print_cone(t_obj *obj, int id);
void		print_cyl(t_obj *obj, int id);
void		print_parsed(t_scene *scene);
void		print_color(t_color color);
void		print_obj(t_scene *scene);
int			a_light_parser(char **elements, t_scene *scene);
int			d_light_parser(char **elements, t_scene *scene);
int			s_light_parser(char **elements, t_scene *scene);
int			sphere_parser(char **elements, t_scene *scene);
int			plane_parser(char **elements, t_scene *scene);
int			cone_parser(char **elements, t_scene *scene);
int			cam_parser(char **elements, t_scene *scene);
int			cyl_parser(char **elements, t_scene *scene);
int			parser(int argc, char **argv, t_data *data);
int			parse_error(char *msg, char **elements);
int			read_file(int fd, t_scene *scene);
int			add_sphere(t_sphere **head);
int			add_plane(t_plane **head);
int			add_cyl(t_cyl **head);

/* ************************************************************************** */
/*                                                                            */
/*   BOOL Functions                                                           */
/*                                                                            */
/* ************************************************************************** */
int			contains_a_light(t_lux *lux);
int			bad_range(float n, float min, float max);
int			bad_coord(char *element);
int			bad_float_coord(char **str);
int			bad_rgb_numbers(char **rgb);
int			bad_rgb(char *element);
int			bad_float(char *str);
int			bad_int(char *str);

/* ************************************************************************** */
/*                                                                            */
/*   Forward Declarations                                                     */
/*                                                                            */
/* ************************************************************************** */
t_vertex	new_vertex(float x, float y, float z);

#endif
