/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:58:49 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static int	open_file(t_graphic *gr);
static int	read_file(int fd, t_graphic *gr);
static void	read_line(char *line, t_color *pixel_color,
				unsigned int *pixel_int, int line_nr);
static int	read_color(char **line);

int	parse_file(t_graphic *gr)
{
	int		fd;

	fd = open_file(gr);
	if (fd == -1)
		return (FAILURE);
	if (read_file(fd, gr) == FAILURE)
		return (FAILURE);
	if (close(fd) == -1)
		return (FAILURE);
	return (SUCCESS);
}

static	int	open_file(t_graphic *gr)
{
	char	*path;
	int		fd;

	(void)gr;
	path = ft_strjoin("src/graphics/files/", gr->title);
	if (path == NULL)
		return (-1);
	fd = open(path, O_RDONLY);
	free(path);
	return (fd);
}

static	int	read_file(int fd, t_graphic *gr)
{
	int		line_nr;
	char	*line;

	line_nr = 0;
	line = get_next_line(fd);
	while (line)
	{
		read_line(line, gr->pixel_color, gr->pixel_int, line_nr);
		free(line);
		line = get_next_line(fd);
		line_nr++;
	}
	if (line_nr != gr->width * gr->height)
		return (FAILURE);
	else
		return (SUCCESS);
}

static void	read_line(char *line, t_color *pixel_color,
			unsigned int *pixel_int, int line_nr)
{
	pixel_color[line_nr].red = read_color(&line);
	pixel_color[line_nr].green = read_color(&line);
	pixel_color[line_nr].blue = read_color(&line);
	pixel_int[line_nr] = pixel_color[line_nr].red << 16
		| pixel_color[line_nr].green << 8
		| pixel_color[line_nr].blue;
}

static int	read_color(char **line)
{
	int	n;

	n = 0;
	while (**line != ' ' && **line != '\n')
	{
		n *= 10;
		n += **line - '0';
		(*line)++;
	}
	if (**line == ' ')
		(*line)++;
	return (n);
}
