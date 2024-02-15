/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:42:45 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 15:44:02 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	parse(char *line, t_scene *scene, char *id_list[8],
		int (*id_funs[8])(char **els, t_scene *scene))
{
	char	**els;
	int		id;

	if (line[0] == '\n')
		return (0);
	els = ft_split(line, ' ');
	if (!(els))
		return (-1);
	id = A_LIGHT;
	while (id <= CONE)
	{
		if (!(ft_strcmp(id_list[id], els[0])))
			return (id_funs[id](els, scene));
		id++;
	}
	return (parse_error("Syntax: Identifier", els));
}

static void	parse_id(int (*id_funs[8])(char **els, t_scene *scene))
{
	id_funs[A_LIGHT] = &a_light_parser;
	id_funs[CAM] = &cam_parser;
	id_funs[S_LIGHT] = &s_light_parser;
	id_funs[SPHERE] = &sphere_parser;
	id_funs[PLANE] = &plane_parser;
	id_funs[CYL] = &cyl_parser;
	id_funs[D_LIGHT] = &d_light_parser;
	id_funs[CONE] = &cone_parser;
}

static void	init_id_list(char *id_list[8])
{
	id_list[A_LIGHT] = "A";
	id_list[CAM] = "C";
	id_list[S_LIGHT] = "L";
	id_list[SPHERE] = "sp";
	id_list[PLANE] = "pl";
	id_list[CYL] = "cy";
	id_list[D_LIGHT] = "dl";
	id_list[CONE] = "cn";
}

int	read_file(int fd, t_scene *scene)
{
	char	*line;
	int		(*id_funs[8])(char **els, t_scene *scene);
	char	*id_list[8];

	init_id_list(id_list);
	parse_id(id_funs);
	scene->nb_obj = 0;
	errno = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (parse(line, scene, id_list, id_funs))
			return (free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	if (errno)
		return (parse_error("Fatal: File", NULL));
	return (SUCCESS);
}
