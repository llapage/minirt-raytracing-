/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_widget.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:38:20 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 08:28:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAV_WIDGET_H
# define NAV_WIDGET_H

# include "graphics.h"
# include "scene.h"
# include "keycodes.h"

enum e_content_types
{
	NAVDEF = 0,
	NAVOBJECTS = 1,
	NAVLIGHTS = 2,
	NAVCAM = 3,
	NAVRENDER = 20,
	NAVRETURN = 21,
	NAVEXPORT = 22,
	NAVSETTINGS = 23,
	NAVEXIT = 24,
	INFIELD_1 = 25,
	INFIELD_2 = 26,
	INFIELD_3 = 27,
	NAVCONFIRM = 28,
	NAVCANCEL = 29,
	NAVOBJ,
	NAVLUX,
	NAV3FLT,
	NAV3INT,
	NAV2INT,
	NAVFLT,
	NAVINT
};

typedef struct s_nav_directions	t_nav_directions;
typedef struct s_nav_graphics	t_nav_graphics;

typedef union u_nav_content
{
	unsigned int	*uint_number;
	float			*float_number;
	t_cam			*cam;
	t_lux			*lux;
	t_obj			*obj;
}	t_nav_content;

typedef struct s_nav
{
	struct s_nav		*parent;
	struct s_nav		*sibling;
	struct s_nav		*child;
	t_graphic			**current_graphic;
	t_graphic			*default_graphic;
	t_graphic			*focus_graphic;
	t_graphic			*select_graphic;
	t_graphic			*alternative_graphic;
	t_pixel				br;
	t_pixel				gp;
	t_pixel				tl;
	union u_nav_content	cont;
	void				(*act)(struct s_nav *, struct s_data *); 
	void				(*scr)(struct s_nav *, struct s_data *, int);
	char				desc[32];
	char				shows;
	char				active;
	char				type;
	char				visibility_lock;
	char				image_lock;
	char				cont_type;
}	t_nav;

typedef struct s_nav_directions
{
	int	self;
	int	parent;
	int	sibling;
	int	child;
}	t_nav_directions;

typedef struct s_nav_graphics
{
	char	*def;
	char	*fcs;
	char	*sel;
	char	*alt;
}	t_nav_graphics;

int				nav_setup(t_data *dt);
void			scroll_pane(t_nav *nav, t_data *dt, int keycode);
void			scroll_pane_down(t_nav *nav, t_nav *bottom);
void			scroll_pane_up(t_nav *nav, t_nav *bottom);
void			move_item_top_set_visibility_and_align_children(t_nav *nav);
void			move_item_down_and_align_children(t_nav *nav);
void			move_item_up_set_visibility_and_align_children(t_nav *nav);
void			move_item_bottom_and_align_children(t_nav *nav, t_nav *bottom);
void			move_item_adjacent(t_nav *nav, t_nav *src);

/* ************************************************************************** */
/*                                                                            */
/*  GET Utilities                                                             */
/*                                                                            */
/* ************************************************************************** */
t_nav			*nav_under_pointer(t_pixel ptr, t_data *dt);
t_nav			*pane_bottom_element(t_nav *nav);
t_nav_graphics	file_names(char *def, char *fcs, char *sel, char *alt);
t_nav			*selected_infield(t_data *dt);
t_nav			*get_top_element(t_nav *nav);
/* ************************************************************************** */
/*                                                                            */
/*  SET Utilities                                                             */
/*                                                                            */
/* ************************************************************************** */

void			change_graphic(t_nav *nav, t_graphic **graphic);
void			do_graph_link(t_nav *nav, t_nav_graphics ng, t_data *dt);
void			focus_item_and_parents(t_nav *nav, t_nav *navdef);
void			focus_item(t_nav *nav);
void			hide_input_dialog(t_data *dt);
void			hide_item(t_nav *nav);
void			hide_main_menu(t_data *dt);
void			hide_this_generation(t_nav *nav);
void			try_hide_item_and_siblings(t_nav *nav);
void			lock_image_item(t_nav *nav);
void			lock_visibility_item(t_nav *nav);
void			lock_visibility_lock_image_and_set_inactive_all(t_data *dt);
void			lock_visibility_this_generation(t_nav *nav);
void			unlock_image_item(t_nav *nav);
void			unlock_visibility_item(t_nav *nav);
void			unlock_visibility_unlock_image_and_set_active_all(t_data *dt);
void			move_item_bottom(t_nav *nav, t_nav *bottom);
void			move_item_down(t_nav *nav);
void			move_item_top(t_nav *nav);
void			move_item_up(t_nav *nav);
void			press_item_and_focus_parents(t_nav *nav, t_nav *navdef);
void			press_item(t_nav *nav);
void			put_if_visible_all(t_data *dt, t_image *img);
void			set_active_item(t_nav *nav);
void			set_active_unlock_image_this_generation(t_nav *nav);
void			set_inactive_item(t_nav *nav);
void			set_fill_im(t_nav *nav, t_data *dt);
void			set_surface_im(t_nav *nav, t_data *dt);
void			set_visible_children(t_nav *nav, t_data *dt);
void			set_visible_item(t_nav *nav);
void			set_visible_main_menu(t_data *dt);
void			set_visible_siblings(t_nav *sib, t_nav *nav, t_data *dt);
void			set_visible_this_generation_and_up(t_nav *nav, t_data *dt);
void			set_visible_this_generation(t_nav *nav, t_data *dt);
void			reset_item(t_nav *nav);
void			try_reset_image_and_siblings(t_nav *nav);
void			put_if_visible_this_generation_and_down(t_nav *nav, t_nav *sib, 
					t_image *img, t_data *dt);
void			set_visible_infields(t_nav *nav, t_nav *sib, t_image *img, 
					t_data *dt);
int				try_reset_image(t_nav *nav);
int				try_hide_item(t_nav *nav);

/* ************************************************************************** */
/*                                                                            */
/*  BOOL Utilities                                                            */
/*                                                                            */
/* ************************************************************************** */
int				drop_down_limit_reached(t_nav *nav, t_data *dt);
int				within_drop_down_limit(t_nav *nav);
int				is_drop_down_bottom(t_nav *nav);
int				is_drop_down_parent(t_nav *nav);
int				is_float(t_nav *nav);
int				is_infield(t_nav *nav, t_data *dt);
int				is_input_button(t_nav *nav, t_data *dt);
int				is_input_dialog(t_nav *nav, t_data *dt);
int				is_focused(t_nav *nav);
int				is_pressed(t_nav *nav);
int				is_default(t_nav *nav);
int				is_alternative(t_nav *nav);
int				is_visible(t_nav *nav);
int				is_main_menu(t_nav *nav, t_data *dt);
int				is_object(t_nav *nav);
int				is_clickable(t_nav *nav);
int				is_scrollable(t_nav *nav);
int				has_child(t_nav *nav);
int				has_more_siblings(t_nav *sib, t_nav *nav);
int				visibility_locked(t_nav *nav);
int				image_locked(t_nav *nav);
int				is_active(t_nav *nav);
#endif
