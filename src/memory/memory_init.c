/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:40:18 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:56:44 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

static void	init_data_error(t_data *dt, t_image *screen_image_image)
{
	free(dt->screen_image);
	free(screen_image_image);
	free(dt->stub_render_image);
	free(dt->full_render_image);
	free(dt->vp);
	free(dt->nav);
	free(dt->hits);
	free(dt->coord_msg);
	printf("Error\n");
	printf("Fatal: Memory allocation\n");
}

static void	do_post_malloc_init(t_data *dt, t_image *screen_image_image)
{
	dt->screen_image->image = screen_image_image;
	dt->screen_image->strings = NULL;
	dt->coord_msg[X] = NULL;
	dt->coord_msg[Y] = NULL;
	dt->nav->sibling = NULL;
	dt->nav->child = NULL;
	dt->nav->parent = NULL;
	dt->mode = LOADING;
	dt->scene_grab = 0;
	dt->visib = new_range(1, FLT_MAX);
	dt->black = get_color(0, 0, 0);
	dt->white = get_color(255, 255, 255);
	dt->loop.button_press = UNSET;
	dt->loop.button_release = UNSET;
	dt->loop.key_press = UNSET;
	dt->loop.mouse_move = UNSET;
	dt->reflections_switch = UNSET;
	dt->anti_aliasing_switch = UNSET;
	nav_init(dt);
}

static int	do_safety(t_data *dt, t_image *screen_image_image)
{
	if (dt->screen_image == NULL
		|| screen_image_image == NULL
		|| dt->coord_msg == NULL
		|| dt->stub_render_image == NULL
		|| dt->full_render_image == NULL
		|| dt->hits == NULL
		|| dt->vp == NULL
		|| dt->nav == NULL)
	{
		init_data_error(dt, screen_image_image);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	do_malloc(t_data *dt, t_image **screen_image_image)
{
	dt->screen_image = malloc(sizeof(t_screen_image));
	*screen_image_image = malloc(sizeof(t_image));
	dt->full_render_image = malloc(sizeof(t_image));
	dt->stub_render_image = malloc(sizeof(t_image));
	dt->coord_msg = malloc(2 * sizeof(char *));
	dt->hits = malloc(S_HEIGHT * S_WIDTH * sizeof(t_hit));
	dt->vp = malloc(sizeof(t_viewport));
	dt->nav = malloc(30 * sizeof(t_nav));
}

int	init_data(t_data *dt)
{
	t_image	*screen_image_image;

	screen_image_image = NULL;
	dt->screen_image = NULL;
	dt->stub_render_image = NULL;
	dt->full_render_image = NULL;
	dt->vp = NULL;
	dt->hits = NULL;
	dt->scene->cam = NULL;
	dt->scene->lux = NULL;
	dt->scene->obj = NULL;
	dt->coord_msg = NULL;
	dt->mlx = NULL;
	dt->nav = NULL;
	dt->graph = NULL;
	dt->states = NULL;
	do_malloc(dt, &screen_image_image);
	if (do_safety(dt, screen_image_image) == SUCCESS)
	{
		do_post_malloc_init(dt, screen_image_image);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}
