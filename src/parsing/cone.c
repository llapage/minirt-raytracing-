/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:42:30 by llapage           #+#    #+#             */
/*   Updated: 2024/01/21 14:01:24 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	cone_parser_4(char **els, t_scene *scene)
{
	scene->obj->gloss = 0;
	if (els[6])
	{
		if (bad_int(els[6])
			|| bad_range(ft_atoi(els[6]), 0, 1000))
			return (parse_error("Syntax: Cone", els));
		scene->obj->gloss = ft_atoi(els[6]);
	}
	scene->obj->refness = 0;
	if (els[6] && els[7])
	{
		if (bad_int(els[7])
			|| bad_range(ft_atoi(els[7]), 0, 1000))
			return (parse_error("Syntax: Cone", els));
		scene->obj->refness = ft_atoi(els[7]);
	}
	free_s_arr(&els);
	return (0);
}

static int	cone_parser_3(char **els, t_scene *scene)
{
	char	**rgb;

	if (bad_float(els[3])
		|| bad_float(els[4])
		|| ft_atof(els[3], &scene->obj->shape.cone->diameter)
		|| ft_atof(els[4], &scene->obj->shape.cone->height)
		|| bad_rgb(els[5]))
		return (parse_error("Syntax: Cone", els));
	rgb = ft_split(els[5], ',');
	if (!rgb || bad_rgb_numbers(rgb))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Cone", els));
	}
	scene->obj->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_s_arr(&rgb);
	return (cone_parser_4(els, scene));
}

static int	cone_parser_2(char **els, t_scene *scene)
{
	char	**coord;
	float	v_x;
	float	v_y;
	float	v_z;

	scene->obj->ctr = &scene->obj->shape.cone->ctr;
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
		return (parse_error("Syntax: Cone", els));
	}
	free_s_arr(&coord);
	scene->obj->shape.cone->axis = new_vector(v_x, v_y, v_z);
	return (cone_parser_3(els, scene));
}

int	cone_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	x;
	float	y;
	float	z;

	if ((ft_strstrlen((const char **)els) != 6
			&& ft_strstrlen((const char **)els) != 7
			&& ft_strstrlen((const char **)els) != 8)
		|| bad_coord(els[1]))
		return (parse_error("Syntax: Cone", els));
	if (new_obj(scene, CONE))
		return (parse_error("Fatal: Memory allocation", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &x)
		|| ft_atof(coord[1], &y)
		|| ft_atof(coord[2], &z))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Cone", els));
	}
	free_s_arr(&coord);
	scene->obj->shape.cone->ctr = new_vertex(x, y, z);
	return (cone_parser_2(els, scene));
}
