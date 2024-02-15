/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:42:38 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:53:49 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

static void	press_key_5(int keycode, t_data *dt)
{
	if (keycode == I_KEY)
	{
		dt->scene->cam->dir = rotate_x(dt->scene->cam->dir, -45);
		init_vp(dt->vp, dt->scene->cam);
		edit_mode(dt);
		render(dt);
	}
}

static void	press_key_4(int keycode, t_data *dt)
{
	if (keycode == J_KEY)
	{
		dt->scene->cam->dir = rotate_y(dt->scene->cam->dir, 45);
		init_vp(dt->vp, dt->scene->cam);
		edit_mode(dt);
		render(dt);
	}
	else if (keycode == L_KEY)
	{
		dt->scene->cam->dir = rotate_y(dt->scene->cam->dir, -45);
		init_vp(dt->vp, dt->scene->cam);
		edit_mode(dt);
		render(dt);
	}
	else if (keycode == K_KEY)
	{
		dt->scene->cam->dir = rotate_x(dt->scene->cam->dir, 45);
		init_vp(dt->vp, dt->scene->cam);
		edit_mode(dt);
		render(dt);
	}
	else
		press_key_5(keycode, dt);
}

static void	press_key_3(int keycode, t_data *dt)
{
	if (keycode == Y_KEY)
	{
		if (dt->curr_obj->type == CYL)
			dt->curr_obj->shape.cyl->axis
				= rotate_y(dt->curr_obj->shape.cyl->axis, 90);
		else if (dt->curr_obj->type == PLANE)
			dt->curr_obj->shape.plane->norm
				= rotate_y(dt->curr_obj->shape.cyl->axis, 90);
		render(dt);
	}
	else if (keycode == Z_KEY)
	{
		if (dt->curr_obj->type == CYL)
			dt->curr_obj->shape.cyl->axis
				= rotate_z(dt->curr_obj->shape.cyl->axis, 90);
		else if (dt->curr_obj->type == PLANE)
			dt->curr_obj->shape.plane->norm
				= rotate_z(dt->curr_obj->shape.cyl->axis, 90);
		render(dt);
	}
	else
		press_key_4(keycode, dt);
}

static void	press_key_2(int keycode, t_data *dt)
{
	if (is_object_transformation_key(keycode) == TRUE)
	{
		if (select_object_under_current_pointer(dt) == SUCCESS)
			edit_mode(dt);
		else
			return ;
	}
	if (keycode == X_KEY)
	{
		if (dt->curr_obj->type == CYL)
			dt->curr_obj->shape.cyl->axis
				= rotate_x(dt->curr_obj->shape.cyl->axis, 90);
		else if (dt->curr_obj->type == PLANE)
			dt->curr_obj->shape.plane->norm
				= rotate_x(dt->curr_obj->shape.cyl->axis, 90);
		render(dt);
	}
	else
		press_key_3(keycode, dt);
}

void	press_key(int keycode, t_data *dt)
{
	if (dt->mode == LOADING)
		return ;
	else if (dt->mode == INPUT)
		user_input(keycode, selected_infield(dt), dt);
	else if (keycode == ESCAPE_KEY)
		press_escape(dt);
	else if (keycode == TAB_KEY)
		press_tab(dt);
	else if (keycode == ENTER_KEY || keycode == NUM_ENTER_KEY)
		press_enter(dt);
	else if (keycode == ARROW_UP_KEY)
		press_arrow_up(dt);
	else if (keycode == ARROW_DOWN_KEY)
		press_arrow_down(dt);
	else if (keycode == ARROW_LEFT_KEY)
		press_arrow_left(dt);
	else if (keycode == ARROW_RIGHT_KEY)
		press_arrow_right(dt);
	else if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY || keycode == Q_KEY
		|| keycode == E_KEY)
		move_cam(keycode, dt);
	else
		press_key_2(keycode, dt);
}
