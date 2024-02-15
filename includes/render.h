/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:24 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:28:44 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdio.h>
# include "t_data.h"
# include "intersect.h"
# include "vector.h"
# include "color.h"
# include "scene.h"
# include "defs.h"
# include "gui.h"
# include "image.h"

t_vertex	px_to_vp(t_pixel px, t_data *dt);
t_vertex	next_sub_px(t_data *dt);
t_vertex	surface_map(t_hit *hit);
t_plane		new_plane(t_vertex vtx, t_vector norm, t_vertex cam);
t_color		get_sphere_light(t_hit *hit, t_data *dt);
t_color		surface_color(t_hit *hit, t_data *dt);
t_color		color_and_light(t_hit *hit, t_data *dt);
t_color		get_light(t_hit *hit, t_data *dt);
t_vector	smooth_intersection_normal(t_hit *hit);
t_hit		*color_trace(t_ray ray, t_data *dt, t_range visib, int depth);
t_hit		*detail_trace(t_data *dt);
t_hit		*standard_trace(t_data *dt);
t_hit		*simple_trace(t_data *dt);
t_hit		*probe(t_ray ray, t_data *dt);
t_hit		*trace(t_ray ray, t_data *dt, int depth);
t_hit		*simple_trace(t_data *dt);
float		reflection(t_hit *hit, t_ray light_ray);
t_unit_rgb	lights_intensity(t_hit *hit, t_data *dt);
void		set_obj_img(t_data *dt, unsigned int light_col, int dark_col);
void		default_mode(t_data *dt);
void		set_new_mode(int mode, t_data *dt);
void		revert_mode(t_data *dt);
void		input_mode(t_data *dt);
void		update_progress_bar(t_data *dt);
void		clear_mut(t_data *dt);
void		do_render(t_data *dt);
void		edit_mode(t_data *dt);
void		set_vars(t_data *dt);
void		set_plane_vars(t_plane *plane, t_data *dt);
void		set_cam_vars(t_data *dt, t_vertex cam_pos);
void		launch(t_data *dt);
void		render(t_data *dt);
void		trace_and_put_pixel(t_data *dt);
void		fill_hit_subsample_gaps(t_hit *hit, t_data *dt);
void		save_color_info(t_hit *hit, t_data *dt);
void		put_color_in_object_images(t_hit *hit, t_data *dt);
void		put_color_in_main_image(t_hit *hit, t_data *dt);
void		put_color(t_hit *hit, t_data *dt);
void		increase(int *counter);
void		set(int *counter);
void		put_color_in_main_image_pixel(t_hit *hit, int i, t_data *dt);
void		put_color_in_obj_image_pixel_horizontal(
				t_hit *hit, t_obj *obj, int i, t_data *dt);
void		put_color_in_obj_image_pixel_vertical(
				t_hit *hit, t_obj *obj, int i, t_data *dt);
void		set_viewport_intersection_point(t_data *dt);
void		set_hit_normal(t_hit *hit, t_ray ray, t_data *dt);
int			edit_render(t_data *dt);
int			rl_out(t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*    GET utility functions                                                   */
/*                                                                            */
/* ************************************************************************** */
int			first_sub_pixel(t_data *dt);
int			first_sub_line(t_data *dt);
t_hit		*current_hit(t_data *dt);
t_ray		ray_from_focal_point_to_viewport_point(t_data *dt);
t_lux		*first_lux(t_data *dt);
t_unit_rgb	rgb_intensity_of(t_lux *lux);
t_ray		from_the_object_towards_the_light(t_hit *hit, t_lux *lux);
float		strenght_of_reflection_back_to_the_light(
				t_hit *hit, t_ray light_ray);
float		strenght_of_reflection_toward_the_viewer(
				t_hit *hit, t_ray light_ray);
t_ray		ray_from_focal_point_to_super_viewport_point(t_data *dt);
int			nb_depth_rays(t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*    SET utility functions                                                   */
/*                                                                            */
/* ************************************************************************** */
void		copy_hit(int col, int line, t_hit *hit, t_data *dt);
void		save_current_hits(t_data *dt);
void		link_object_color(t_hit *hit);
void		initialise_hit(t_hit *hit, t_data *dt);
void		update_nearest(t_obj *obj, float objects_distance, t_hit *hit);
void		mark_object_as_hit_or_not_hit(
				t_obj *obj, float objects_distance, t_data *dt);
void		save_intersection_point_and_norm(t_hit *hit, t_ray ray);
int			there_are_super_lines_left(t_data *dt);
int			there_are_super_pixels_left(t_data *dt);
void		set_viewport_intersection_point(t_data *dt);
void		add_color(t_hit *hit, t_color *color);
void		zero(float *f);
void		next_lux(t_lux **lux);
void		set_color_intensity(t_color *color, t_unit_rgb intensity);
void		weaken_scalar_by_the_lights_distance(
				float *scalar, t_ray light_ray);
void		apply_object_glossiness_to(
				float *scalar, t_hit *hit, t_ray light_ray);
void		clear(
				t_color *color, t_data *dt);
void		save_average(t_color color, t_data *dt);
void		test_done_message(int start, t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*    BOOL utility functions                                                  */
/*                                                                            */
/* ************************************************************************** */
int			there_are_lines_left(t_data *dt);
int			there_are_pixels_left(t_data *dt);
int			intersects_an_object(t_hit *ht);
int			new_nearest_object(float distance, t_hit *hit);
int			there_are_sub_lines_left(int line, int first_line, t_data *dt);
int			there_are_sub_pixels_left(int col, t_data *dt);
int			there_are_more_sub_pixels(int i, t_data *dt);
int			ray_hit_object(t_obj *obj, t_data *dt);
int			is_ambient_light(t_lux *lux);
int			blocks(t_obj *obj, t_ray light, t_data *dt);
int			is_itself(t_obj *obj, t_hit *hit);
int			is_shadow(t_ray light, t_hit *hit, t_data *dt);
int			is_negative_or_insignificant(float f);
int			not_a_glossy_object(t_hit *hit);

#endif
