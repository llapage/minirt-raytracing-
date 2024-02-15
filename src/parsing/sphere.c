/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:52:44 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 13:59:58 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	sphere_parser_3(char **els, t_scene *scene)
{
	scene->obj->gloss = 0;
	if (els[4])
	{
		if (bad_int(els[4])
			|| bad_range(ft_atoi(els[4]), 0, 1000))
			return (parse_error("Syntax: Sphere", els));
		scene->obj->gloss = ft_atoi(els[4]);
	}
	scene->obj->refness = 0;
	if (els[4] && els[5])
	{
		if (bad_int(els[5])
			|| bad_range(ft_atoi(els[5]), 0, 1000))
			return (parse_error("Syntax: Sphere", els));
		scene->obj->refness = ft_atoi(els[5]);
	}
	free_s_arr(&els);
	return (0);
}

static int	sphere_parser_2(char **els, t_scene *scene)
{
	char	**rgb;

	scene->obj->ctr = &scene->obj->shape.sphere->ctr;
	rgb = ft_split(els[3], ',');
	if (bad_rgb(els[3]))
		return (parse_error("Syntax: Sphere", els));
	if (!rgb || bad_rgb_numbers(rgb) || bad_rgb(els[3])
		|| ft_atof(els[2], &scene->obj->shape.sphere->diameter))
	{
		free_s_arr(&rgb);
		return (parse_error("Syntax: Sphere", els));
	}
	scene->obj->color = get_color(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_s_arr(&rgb);
	scene->obj->shape.sphere->radius = scene->obj->shape.sphere->diameter / 2;
	sphere_parser_3(els, scene);
	return (0);
}

int	sphere_parser(char **els, t_scene *scene)
{
	char	**coord;
	float	x;
	float	y;
	float	z;

	if ((ft_strstrlen((const char **)els) != 4
			&& ft_strstrlen((const char **)els) != 5
			&& ft_strstrlen((const char **)els) != 6)
		|| bad_coord(els[1]))
		return (parse_error("Syntax: Sphere", els));
	if (new_obj(scene, SPHERE))
		return (parse_error("Fatal: Memory allocation", els));
	coord = ft_split(els[1], ',');
	if (!coord
		|| ft_strstrlen((const char **) coord) != 3
		|| ft_atof(coord[0], &x)
		|| ft_atof(coord[1], &y)
		|| ft_atof(coord[2], &z)
		|| bad_float(els[2]))
		return (free_s_arr(&coord), parse_error("Syntax: Sphere", els));
	free_s_arr(&coord);
	scene->obj->shape.sphere->ctr = new_vertex(x, y, z);
	return (sphere_parser_2(els, scene));
}
