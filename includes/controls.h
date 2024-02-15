/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:01:55 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:45:25 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "navigation.h"
# include "transform.h"
# include "t_data.h"
# include "input.h"
# include "scene.h"
# include "defs.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	BUTTON_RELEASE_MASK = 1L<<3,
	NO_EVENT_MASK = 0,
	POINTER_MOTION_MASK = 1L<<6,
	KEY_PRESS_MASK = 1L<<0
};

int		button_release_hook(int keycode, int x, int y, t_data *data);
int		button_press_hook(int keycode, int x, int y, t_data *data);
int		mouse_move_hook(int x, int y, t_data *data);
int		key_press_hook(int keycode, t_data *dt);
int		display_move_info(t_pixel ptr, t_data *dt);
int		drop_object(t_pixel ptr, t_data *dt);
int		unselect_object(t_data *dt);
int		select_object(t_pixel ptr, t_data *dt);
int		is_object_transformation_key(int keycode);
void	move_mouse(t_pixel ptr, t_data *data);
void	press_key(int keycode, t_data *dt);
void	press_button(int keycode, t_pixel pointer_location, t_data *dt);
void	release_button(int keycode, t_pixel pointer_location, t_data *dt);
void	right_release(t_pixel ptr, t_data *dt);
void	left_release(t_pixel ptr, t_data *dt);
void	left_click(t_pixel ptr, t_data *dt);
void	scroll(t_pixel ptr, int keycode, t_data *dt);
void	show_str(t_data *dt, char *s, t_pixel px, int color);
void	show_obj(t_data *dt);
void	show_move_strings(t_pixel ptr, t_data *dt);
void	set_move_strings(t_data *dt);
void	press_escape(t_data *dt);
void	press_tab(t_data *dt);
void	press_enter(t_data *dt);
void	press_arrow_up(t_data *dt);
void	press_arrow_down(t_data *dt);
void	press_arrow_left(t_data *dt);
void	press_arrow_right(t_data *dt);

#endif
