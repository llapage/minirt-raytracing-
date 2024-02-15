/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:06:25 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:43:06 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

static	void	free_data_continued(t_data *dt)
{
	free_graph(dt->graph);
	clear_history(dt);
	free(dt->vp);
	free_nav(dt->nav);
	free(dt->screen_image->image);
	ft_lstclear(&dt->screen_image->strings, free_mlx_string);
	free(dt->screen_image);
	free(dt->stub_render_image);
	free(dt->full_render_image);
	free(dt->hits);
	free_s_arr(&dt->coord_msg);
	free(dt->mlx);
}

void	free_data(t_data *dt)
{
	if (dt->scene)
	{
		free(dt->scene->cam);
		free_obj(dt);
		free_lux(dt->scene);
	}
	if (dt->mlx)
	{
		mlx_destroy_image(dt->mlx, dt->full_render_image->ptr);
		mlx_destroy_image(dt->mlx, dt->screen_image->image->ptr);
		mlx_destroy_image(dt->mlx, dt->stub_render_image->ptr);
		mlx_destroy_window(dt->mlx, dt->win);
	}
	free_data_continued(dt);
}
