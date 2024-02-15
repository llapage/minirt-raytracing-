/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:28:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/15 23:05:05 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	print_ambient(t_a_light *amb)
{
	printf("AMBIENT LIGHT\n");
	printf("ratio:\t\t%f\n", amb->ratio);
	print_color(amb->color);
}

static void	print_dir(t_d_light *dir)
{
	printf("DIRECTIONAL LIGHT\n");
	print_vector("direction", dir->dir);
	printf("brightness:\t%f\n", dir->bright);
	print_color(dir->color);
}

static void	print_spot(t_s_light *spot)
{
	printf("SPOTLIGHT\n");
	print_vertex("position", spot->pos);
	printf("brightness:\t%f\n", spot->bright);
	print_color(spot->color);
}

void	print_parsed(t_scene *scene)
{
	t_lux	*lux;

	printf("CAMERA\n");
	print_vertex("position", scene->cam->pos);
	print_vector("direction", (scene->cam->dir));
	printf("Field of View:\t%d\n\n", scene->cam->fov);
	lux = scene->lux;
	while (lux)
	{
		if (lux->type == AMBIENT)
			print_ambient(lux->src.amb);
		else if (lux->type == SPOT)
			print_spot(lux->src.spot);
		else if (lux->type == DIRECTIONAL)
			print_dir(lux->src.dir);
		printf("\n");
		lux = lux->next;
	}
	print_obj(scene);
}
