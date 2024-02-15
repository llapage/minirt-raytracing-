/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:27:47 by llapage           #+#    #+#             */
/*   Updated: 2024/01/21 18:53:10 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parse_error(char *msg, char **els)
{
	free_s_arr(&els);
	printf("Error\n%s\n", msg);
	return (FAILURE);
}

static int	open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (FAILURE);
	return (SUCCESS);
}

static int	is_complete(t_scene *scene)
{
	t_lux	*lux;
	int		amb;
	int		spot;

	if (!scene || !scene->cam)
		return (0);
	amb = 0;
	spot = 0;
	lux = scene->lux;
	while (lux)
	{
		if (lux->type == AMBIENT)
			amb = 1;
		else if (lux->type == SPOT)
			spot = 1;
		lux = lux->next;
	}
	if (!amb || !spot)
		return (FALSE);
	return (TRUE);
}

int	parser(int argc, char **argv, t_data *dt)
{
	int		fd;

	if (S_WIDTH < 680 || S_HEIGHT < 480)
		return (parse_error("Resolution too low", NULL));
	if (S_WIDTH > 2560 || S_HEIGHT > 1440)
		return (parse_error("Resolution too high", NULL));
	if (argc != 2)
		return (parse_error("Fatal: Arguments", NULL));
	if (ft_strlen(argv[1]) <= 3
		|| ft_strcmp(&argv[1][ft_strlen(argv[1]) - 3], ".rt"))
		return (parse_error("Fatal: File type", NULL));
	if (open_file(argv[1], &fd) == FAILURE)
		return (parse_error("Fatal: File", NULL));
	if (read_file(fd, dt->scene) == FAILURE)
		return (FAILURE);
	if (close(fd) == -1)
		return (parse_error("Fatal: File", NULL));
	if (is_complete(dt->scene) == FALSE)
		return (parse_error("Fatal: File content", NULL));
	set_vars(dt);
	return (SUCCESS);
}
