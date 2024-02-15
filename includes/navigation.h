/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:22 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 21:19:20 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAVIGATION_H
# define NAVIGATION_H

# include <math.h>
# include <stdlib.h>
# include "nav_widget.h"
# include "render.h"
# include "ftoa.h"
# include "tiff.h"
# include "gui.h"

typedef struct s_data	t_data;
typedef struct s_cam	t_cam;
typedef struct s_img	t_image;
typedef struct s_lux	t_lux;
typedef struct s_obj	t_obj;

int		focus_widget(t_pixel ptr, t_data *dt);
int		press_widget(t_pixel ptr, t_data *dt);
int		select_widget(t_pixel ptr, t_data *dt);
int		scroll_widget(t_pixel ptr, t_data *dt, int keycode);
int		reset_widgets(t_data *dt);
int		get_scroll_direction(int keycode);
int		info_display(t_pixel ptr, t_data *dt);
void	press_item(t_nav *nav);
void	widget_loop(t_nav *nav, t_data *dt);
void	start_input(t_nav *nav, t_data *dt);
void	input_dialog_link_item(t_nav *nav, t_data *dt);
void	repush_input_dialog_strings_and_display_screen_image(t_data *dt);
void	show_sub_menu(t_pixel ptr, t_data *dt);
char	*put_color_label_get_addr(t_pixel px, t_nav *nav, t_image *img);
void	put_color_label(t_nav *nav, t_image *img);
void	put_color_labels(t_data *dt, t_image *img);
void	display_main_image(t_data *dt);
void	display_screen_image(t_data *dt);
void	re_show_menu(t_nav *nav, t_data *dt);
void	execute_click(t_nav *nav, t_data *dt);
void	execute_scroll(t_nav *nav, t_data *dt, int keycode);
void	put_menu(t_data *dt);
void	unset_sub_menu(t_data *dt);
void	wrap_unsigned(unsigned int *n, unsigned int limit);
void	export_out(t_nav *nav, t_data *dt);
void	shut_down(t_nav *nav, t_data *dt);
void	select_undo(t_nav *nav, t_data *dt);
void	select_render(t_nav *nav, t_data *dt);
void	scroll_fill(t_nav *nav, t_data *dt, int keycode);
void	scroll_surface(t_nav *nav, t_data *dt, int keycode);
void	push_screen_string(char *string, t_pixel position, unsigned int color,
			t_data *dt);
void	scroll_and_wrap_enum(unsigned int *enum_ptr, int keycode, 
			unsigned int limit);
void	switch_reflections(t_nav *nav, t_data *dt);
void	switch_anti_aliasing(t_nav *nav, t_data *dt);

#endif
