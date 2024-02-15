/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:48:13 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 13:59:01 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	plane_parser_4(char **els, t_scene *scene)
{
	scene->obj->gloss = 0;
	if (els[4])
	{
		if (bad_int(els[4])
			|| bad_range(ft_atoi(els[4]), 0, 1000))
			return (parse_error("Syntax: Cylinder", els));
		scene->obj->gloss = ft_atoi(els[4]);
	}
	scene->obj->refness = 0;
	if (els[4] && els[5])
	{
		if (bad_int(els[5])
			|| bad_range(ft_atoi(els[5]), 0, 1000))
			return (parse_error("Syntax: Cylinder", els));
		scene->obj->refness = ft_atoi(els[5]);
	}
	free_s_arr(&els);
	return (0);
}

static int	plane_parser_3(char **els, t_scene *scene)
{
	char	**rgb;

	if (bad_rgb(els[3]))
		return (parse_error("Syntax: Plane", els));
	rgb = ft_split(els[3], ',');
	if (!rgb || bad_rgb_numbers(rgb))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Plane", els));
	}
	scene->obj->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_s_arr(&rgb);
	plane_parser_4(els, scene);
	return (0);
}

static int	plane_parser_2(char **els, t_scene *scene)
{
	char	**coord;
	float	v_x;
	float	v_y;
	float	v_z;

	scene->obj->ctr = &scene->obj->shape.plane->ctr;
	coord = ft_split(els[2], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &v_x)
		|| ft_atof(coord[1], &v_y)
		|| ft_atof(coord[2], &v_z)
		|| bad_range(v_x, -1, 1)
		|| bad_range(v_y, -1, 1)
		|| bad_range(v_z, -1, 1)
		|| bad_coord(els[2]))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Plane", els));
	}
	scene->obj->shape.plane->norm = new_vector(v_x, v_y, v_z);
	free_s_arr(&coord);
	return (plane_parser_3(els, scene));
}

int	plane_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	x;
	float	y;
	float	z;

	if ((ft_strstrlen((const char **)els) != 4
			&& ft_strstrlen((const char **)els) != 5
			&& ft_strstrlen((const char **)els) != 6)
		|| bad_coord(els[1]))
		return (parse_error("Syntax: Plane", els));
	if (new_obj(scene, PLANE))
		return (parse_error("Fatal: Memory allocation", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &x)
		|| ft_atof(coord[1], &y)
		|| ft_atof(coord[2], &z))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Plane", els));
	}
	free_s_arr(&coord);
	scene->obj->shape.plane->ctr = new_vertex(x, y, z);
	return (plane_parser_2(els, scene));
}
