/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_widget_setup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:22 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 21:16:33 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAV_WIDGET_SETUP_H
# define NAV_WIDGET_SETUP_H

# define DO_NOT_LINK -1

# include "nav_widget.h"

t_nav_directions	nav_dir(int self, int tab, int esc, int ent);
int					nav_a_light(t_nav *parent, t_lux *lux, t_data *dt);
int					nav_d_light(t_nav *parent, t_lux *lux, t_data *dt);
int					nav_s_light(t_nav *parent, t_lux *lux, t_data *dt);
int					nav_sphere(t_nav *parent, t_obj *obj, t_data *dt);
int					nav_plane(t_nav *parent, t_obj *obj, t_data *dt);
int					nav_cone(t_nav *parent, t_obj *obj, t_data *dt);
int					nav_cyl(t_nav *parent, t_obj *obj, t_data *dt);
int					nav_light(t_data *dt);
int					nav_obj(t_data *dt);
void				set_desc(char *desc, t_nav *nav);
void				set_next_pos(t_nav *nav, t_nav *obs, int nb);
void				set_pos(t_nav *nav);
void				link_graph(t_nav *nav, t_nav *sib, t_data *dt);
void				set_act(t_nav *nav, int n, void (*f)(t_nav *, t_data *));
void				set_pos_rt(t_nav *nav, t_nav *parent, int n); 
void				set_cam_pos(t_nav *nav);
void				set_settings_pos(t_nav *nav);
void				nav_cam(t_data *dt);
void				nav_settings(t_data *dt);
void				set_nav(t_nav *def, int type, char *desc, 
						t_nav_directions nd);

/* ************************************************************************** */
/*                                                                            */
/*   Forward declarations                                                     */
/*                                                                            */
/* ************************************************************************** */
void				input_mode_init(t_nav *nav, t_data *dt);
void				select_undo(t_nav *nav, t_data *dt);
void				select_render(t_nav *nav, t_data *dt);
void				confirm_input(t_nav *nav, t_data *dt);
void				cancel_input(t_nav *nav, t_data *dt);
void				start_input(t_nav *nav, t_data *dt);
void				shut_down(t_nav *nav, t_data *dt);
void				export_out(t_nav *nav, t_data *dt);
void				scroll_fill(t_nav *nav, t_data *dt, int keycode);
void				scroll_surface(t_nav *nav, t_data *dt, int keycode);
void				switch_reflections(t_nav *nav, t_data *dt);
void				switch_anti_aliasing(t_nav *nav, t_data *dt);

#endif
