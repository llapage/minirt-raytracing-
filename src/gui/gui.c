/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:45:44 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 18:49:46 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gui.h"

int	exit_minirt(t_data *dt)
{
	printf("Exiting MiniRT..\n");
	free_data(dt);
	exit(EXIT_SUCCESS);
}

static void	gui_new_image(t_data *dt)
{
	t_obj	*obj;

	new_image(dt->mlx, dt->full_render_image, S_WIDTH, S_HEIGHT);
	dt->bpp = dt->full_render_image->bits_per_pixel;
	new_image(dt->mlx, dt->stub_render_image, S_WIDTH, S_HEIGHT);
	new_image(dt->mlx, dt->screen_image->image, S_WIDTH, S_HEIGHT);
	dt->render_image_pointer = dt->full_render_image;
	obj = dt->scene->obj;
	while (obj)
	{
		new_image(dt->mlx, obj->full_render_image, S_WIDTH, S_HEIGHT);
		new_image(dt->mlx, obj->stub_render_image, S_WIDTH, S_HEIGHT);
		obj->render_image_pointer = obj->full_render_image;
		obj = obj->next;
	}
}

static int	gui_init_2(t_data *dt)
{
	int	i;

	i = 0;
	while (i < S_WIDTH * S_HEIGHT)
		dt->blk_scrn.pixels[i++] = 0;
	gui_new_image(dt);
	return (SUCCESS);
}

int	gui_init(t_data *dt)
{
	init_vp(dt->vp, dt->scene->cam);
	dt->mlx = mlx_init();
	if (dt->mlx == NULL)
		return (FAILURE);
	dt->win = mlx_new_window(dt->mlx,
			S_WIDTH, S_HEIGHT, "MiniRT");
	if (dt->win == NULL)
		return (FAILURE);
	mlx_mouse_hook(dt->win, button_press_hook, dt);
	mlx_hook(dt->win, ON_MOUSEUP, BUTTON_RELEASE_MASK, button_release_hook, dt);
	if (MAC_OS)
		mlx_hook(dt->win, ON_MOUSEMOVE, NO_EVENT_MASK, mouse_move_hook, dt);
	else
		mlx_hook(dt->win, ON_MOUSEMOVE, POINTER_MOTION_MASK, 
			mouse_move_hook, dt);
	mlx_hook(dt->win, ON_DESTROY, NO_EVENT_MASK, exit_minirt, dt);
	mlx_hook(dt->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press_hook, dt);
	dt->grab = 0;
	dt->in_prog = 0;
	dt->bgc = get_bg_col();
	return (gui_init_2(dt));
}
