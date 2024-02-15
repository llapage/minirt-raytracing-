/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:54:33 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:36:48 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	cam_parser_2(char **els, t_scene *scene)
{
	char	**coord;
	float	v_x;
	float	v_y;
	float	v_z;

	coord = ft_split(els[2], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &v_x)
		|| ft_atof(coord[1], &v_y)
		|| ft_atof(coord[2], &v_z)
		|| bad_range(v_x, -1, 1)
		|| bad_range(v_y, -1, 1)
		|| bad_range(v_z, -1, 1)
		|| bad_int(els[3])
		|| bad_range(ft_atoi(els[3]), 0, 180))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Camera", els));
	}
	free_s_arr(&coord);
	scene->cam->dir = new_vector(v_x, v_y, v_z);
	scene->cam->fov = (unsigned char)ft_atoi(els[3]);
	free_s_arr(&els);
	return (0);
}

int	cam_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	x;
	float	y;
	float	z;

	if (scene->cam)
		return (parse_error("Syntax: Double entry", els));
	scene->cam = malloc(sizeof(t_cam));
	if (!scene->cam)
		return (parse_error("Failed to allocate Camera", els));
	if (ft_strstrlen((const char **)els) != 4
		|| bad_coord(els[1]) || bad_coord(els[2]))
		return (parse_error("Syntax: Camera", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &x) || ft_atof(coord[1], &y)
		|| ft_atof(coord[2], &z))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Camera", els));
	}
	free_s_arr(&coord);
	scene->cam->pos = new_vertex(x, y, z);
	return (cam_parser_2(els, scene));
}
