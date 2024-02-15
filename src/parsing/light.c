/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:41:45 by llapage           #+#    #+#             */
/*   Updated: 2024/01/29 14:41:14 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	a_light_parser(char **els, t_scene *scene)
{
	char	**rgb;

	if (contains_a_light(scene->lux))
		return (parse_error("Syntax: Double entry", els));
	if (new_lux(scene, AMBIENT))
		return (parse_error("Fatal: Memory allocation", els));
	if (ft_strstrlen((const char **)els) != 3
		|| bad_float(els[1])
		|| ft_atof(els[1], &scene->lux->bright)
		|| bad_range(scene->lux->bright, 0, 1)
		|| bad_rgb(els[2]))
		return (parse_error("Syntax: Ambient light", els));
	rgb = ft_split(els[2], ',');
	if (!rgb || bad_rgb_numbers(rgb))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Ambient light", els));
	}
	scene->lux->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	scene->lux->src.amb->color = scene->lux->color;
	free_s_arr(&rgb);
	free_s_arr(&els);
	return (0);
}

static int	s_light_parser_2(char **els, t_scene *scene)
{
	char	**rgb;

	if (bad_float(els[2])
		|| ft_atof(els[2], &scene->lux->bright)
		|| bad_range(scene->lux->bright, 0, 1))
		return (parse_error("Syntax: Light", els));
	scene->lux->color = get_color(255, 255, 255);
	if (!els[3])
		return (0);
	if (bad_rgb(els[3]))
		return (parse_error("Syntax: Light", els));
	rgb = ft_split(els[3], ',');
	if (!rgb || bad_rgb_numbers(rgb))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Light", els));
	}
	scene->lux->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	scene->lux->src.spot->color = scene->lux->color;
	free_s_arr(&rgb);
	free_s_arr(&els);
	return (0);
}

int	s_light_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	x;
	float	y;
	float	z;

	if (new_lux(scene, SPOT))
		return (parse_error("Fatal: Memory allocation", els));
	if (ft_strstrlen((const char **)els) < 3
		|| ft_strstrlen((const char **)els) > 4
		|| bad_coord(els[1]))
		return (parse_error("Syntax: Light", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &x)
		|| ft_atof(coord[1], &y)
		|| ft_atof(coord[2], &z))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Light", els));
	}
	free_s_arr(&coord);
	scene->lux->src.spot->pos = new_vertex(x, y, z);
	return (s_light_parser_2(els, scene));
}

static int	d_light_parser_2(char **els, t_scene *scene)
{
	char	**rgb;

	if (bad_range(scene->lux->src.dir->dir.x, -1, 1)
		|| bad_range(scene->lux->src.dir->dir.y, -1, 1)
		|| bad_range(scene->lux->src.dir->dir.z, -1, 1)
		|| bad_float(els[2])
		|| ft_atof(els[2], &scene->lux->bright)
		|| bad_range(scene->lux->bright, 0, 1)
		|| bad_rgb(els[3]))
		return (parse_error("Syntax: Directional light", els));
	rgb = ft_split(els[3], ',');
	if (!rgb || bad_rgb_numbers(rgb))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Directional light", els));
	}
	scene->lux->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	scene->lux->src.dir->color = scene->lux->color;
	free_s_arr(&rgb);
	free_s_arr(&els);
	return (0);
}

int	d_light_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	v_x;
	float	v_y;
	float	v_z;

	if (ft_strstrlen((const char **)els) != 4
		|| bad_coord(els[1]))
		return (parse_error("Syntax: Directional light", els));
	if (new_lux(scene, DIRECTIONAL))
		return (parse_error("Fatal: Memory allocation", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| bad_coord(els[1])
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &v_x)
		|| ft_atof(coord[1], &v_y)
		|| ft_atof(coord[2], &v_z))
	{
		free_s_arr(&coord);
		return (parse_error("Syntax: Directional light", els));
	}
	scene->lux->src.dir->dir = new_vector(v_x, v_y, v_z);
	free_s_arr(&coord);
	return (d_light_parser_2(els, scene));
}
