/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:48:47 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:39:43 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "vector.h"
# include "scene.h"

typedef struct s_cam	t_cam;
typedef struct s_obj	t_obj;

typedef struct s_viewport
{
	t_vertex	top_left_corn;
	t_vertex	top_left_px;
	t_vector	px_delt_u;
	t_vector	px_delt_v;
	t_vector	u_vec;
	t_vector	v_vec;
	t_vertex	ctr;
	t_vertex	cam;
	t_plane		pln;
	float		focal_len;
	float		diag_fov;
	float		height;
	float		width;
	int			sqrt_supsam;
	int			supsam;
	int			b_offs;
}	t_viewport;

void	init_vp(t_viewport *vp, t_cam *cam);
void	calculate_horizontal_orientation(t_viewport *vp, t_cam *cam);
void	calculate_vertical_orientation(t_viewport *vp, t_cam *cam);
void	calculate_top_left_corner_position(t_viewport *vp, t_cam *cam);
void	calculate_top_left_pixel_projection_position(t_viewport *vp);
void	calculate_focal_length(t_viewport *vp, t_cam *cam);
void	calculate_diagonal_field_of_view(t_viewport *vp);
void	calculate_centre(t_viewport *vp, t_cam *cam);
void	calculate_distance_between_projected_screen_pixels(t_viewport *vp);

/* ************************************************************************** */
/*                                                                            */
/*   GET functions                                                            */
/*                                                                            */
/* ************************************************************************** */
int		round_next_square(int n);
/* ************************************************************************** */
/*                                                                            */
/*   SET functions                                                            */
/*                                                                            */
/* ************************************************************************** */
void	set_plane(t_plane *pln, t_viewport *vp, t_cam *cam);
void	set_size(t_viewport *vp, float width, float height);
void	link_focal_point(t_viewport *vp, t_cam *cam);

#endif
