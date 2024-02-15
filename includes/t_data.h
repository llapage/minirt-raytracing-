/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:21:25 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:49:10 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

# include "vector.h"
# include "scene.h"
# include "color.h"
# include "image.h"
# include "os_def.h"

enum e_states
{
	LOADING,
	DEFAULT,
	EDIT,
	NAV,
	INPUT
};

enum e_render_modes
{
	LOWRES,
	STD
};

typedef enum e_loop_instruction
{
	KEY_PRESS,
	BUTTON_PRESS,
	BUTTON_RELEASE,
	MOUSE_MOVE
}	t_loop_instruction;

typedef struct s_viewport	t_viewport;
typedef struct s_graphic	t_graphic;
typedef struct s_state		t_state;
typedef struct s_nav		t_nav;
typedef struct s_obj		t_obj;

typedef struct s_hit
{
	t_vector	ctr_hit_vec;
	t_vertex	vtx;
	t_color		color;
	float		dist;
	t_obj		*obj;
	t_ray		norm;
	t_ray		refl;
	t_ray		src;
}	t_hit;

typedef struct s_screen_image
{
	t_image		*image;
	t_image		**render_image;
	t_list		*strings;
}	t_screen_image;

typedef struct s_loop
{
	int			button_press;
	int			button_release;
	int			key_press;
	int			mouse_move;
	int			button_press_keycode;
	int			button_release_keycode;
	int			key_press_keycode;
	t_pixel		mouse_move_pointer_location;
	t_pixel		button_press_pointer_location;
	t_pixel		button_release_pointer_location;
}	t_loop;

typedef struct s_data
{
	t_viewport		*vp;
	t_screen		blk_scrn;
	t_vertex		sub_px;
	t_vertex		vp_vtx;
	t_graphic		*graph;
	t_pixel			click_px;
	t_pixel			px;
	t_pixel			ptr;
	t_state			*states;
	t_state			*restore_point;
	t_scene			*scene;
	t_range			visib;
	t_range			prog;
	t_color			black;
	t_color			white;
	t_color			bgc;
	t_nav			*nav_press;
	t_nav			*nav_loc;
	t_nav			*nav;
	t_image			*stub_render_image;
	t_image			*full_render_image;
	t_image			*render_image_pointer;
	t_screen_image	*screen_image;
	t_obj			*curr_obj;
	t_hit			*hits;
	t_hit			new_hit;
	t_loop			loop;
	char			**coord_msg;
	char			mode_prev;
	char			in_prog;
	char			state;
	char			grab;
	char			scene_grab;
	char			mode;
	char			bpp;
	char			sub_samples;
	char			qlt;
	void			*input_addr;
	void			*mlx;
	void			*win;
	int				input_type;
	int				cursor_pos;
	int				sub_line;
	int				sub_col;
	int				obj_sel;
	int				x_diff;
	int				y_diff;
	int				ray_count;
	unsigned int	reflections_switch;
	unsigned int	anti_aliasing_switch;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*    GET functions                                                           */
/*                                                                            */
/* ************************************************************************** */
int		*loop_instruction_address(t_loop_instruction instruction, t_data *dt);
t_obj	*first_object(t_data *dt);
t_obj	*current_object(t_data *dt);
t_obj	*object_under_pointer(t_pixel ptr, t_data *dt);
void	*current_shape(t_data *dt);
t_hit	*hit_under_pointer(t_pixel ptr, t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*    SET functions                                                           */
/*                                                                            */
/* ************************************************************************** */
int		set_current_object(t_obj *obj, t_data *dt);
int		request_instruction(t_loop_instruction instruction, t_data *dt);
int		select_object_under_current_pointer(t_data *dt);
void	unset_current_object(t_data *dt);
void	grab_object(t_data *dt);
void	release_object(t_data *dt);
void	set_first_line(t_data *dt);
void	set_first_pixel(t_data *dt);
void	set_next_line(t_data *dt);
void	set_next_pixel(t_data *dt);
void	set_first_super_line(t_data *dt);
void	set_first_super_pixel(t_data *dt);
void	set_next_super_line(t_data *dt);
void	set_next_super_pixel(t_data *dt);
void	calculate_movement(t_pixel ptr, t_data *dt);
void	reset_movement(t_data *dt);
void	save_click_location(t_pixel ptr, t_data *dt);
void	set_render_image_to(t_image **img, t_data *dt);
void	put_render_image(t_data *dt);
void	put_screen_strings(t_data *dt);
void	clear_screen_strings(t_data *dt);
void	clear_instruction(t_loop_instruction instruction, t_data *dt);
void	next_object_loop(t_obj **obj, t_data *dt);
void	clear_history(t_data *dt);
void	object_selection(t_obj *obj, t_data *dt);
void	object_unselection(t_data *dt);
void	save_current_object_state(t_data *dt);
void	set_switch(unsigned int	*the_switch);
void	unset_switch(unsigned int *the_switch);
void	switch_on_off(unsigned int *the_switch);
void	grab_scene(t_data *dt);
void	release_scene(t_data *dt);
void	save_cam_and_vp_state(t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*    BOOL functions                                                          */
/*                                                                            */
/* ************************************************************************** */
int		rendering_a_stub(t_data *dt);
int		in_default_mode(t_data *dt);
int		in_input_mode(t_data *dt);
int		in_edit_mode(t_data *dt);
int		is_selected_object(t_obj *obj, t_data *dt);
int		is_unselected_object(t_obj *obj, t_data *dt);
int		object_moved(t_data *dt);
int		grabbed_object(t_data *dt);
int		grabbed_scene(t_data *dt);
int		object_selected(t_data *dt);
int		active_sub_menu(t_data *dt);
int		was_default_mode(t_data *dt);
int		was_input_mode(t_data *dt);
int		was_edit_mode(t_data *dt);
int		is_set(unsigned int the_switch);

/* ************************************************************************** */
/*                                                                            */
/*    Forward declarations                                                    */
/*                                                                            */
/* ************************************************************************** */
t_obj	*save_obj_state(t_obj *obj, t_data *dt);
void	put_if_visible_all(t_data *dt, t_image *img);
void	put_color_labels(t_data *dt, t_image *img);
void	free_mlx_string(void *mlx_string);
void	clear_all_states(t_state **states);
void	set_new_mode(int mode, t_data *dt);
void	revert_mode(t_data *dt);
void	put_graphic_named(char *title, t_pixel gp, t_image *img, t_data *dt);

#endif
