/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:56:43 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 20:05:52 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define START_OF_ENUM 0

# include "vector.h"
# include "color.h"
# include "defs.h"

typedef struct s_img	t_image;
typedef struct s_data	t_data;
void	*save_state(void *addr, char type, t_data *dt);

typedef enum s_fill
{
	SOLID_FILL,
	CHECKER_FILL,
	PERLIN_FILL,
	EARTH_FILL,
	MARS_FILL,
	VENUS_FILL,
	SUN_FILL,
	MOON_FILL,
	END_OF_FILL_ENUM
}	t_fill;

typedef enum s_surface
{
	SMOOTH_SURFACE,
	PERLIN_SURFACE,
	EARTH_SURFACE,
	MOON_SURFACE,
	END_OF_SURFACE_ENUM
}	t_surface;

typedef struct s_plane
{
	t_vector	cam_ctr_vec;
	t_vector	ctr_cam_vec;
	t_vector	inv_norm;
	t_vector	norm;
	t_vertex	ctr;
	float		ctr_cam_sqlen;
	float		ctr_cam_dot_norm;
	float		ctr_cam_dot_norm_sqrd;
	float		trinomial_c;
}	t_plane;

typedef struct s_cyl
{
	t_vector	cam_ctr_vec;
	t_vector	ctr_cam_vec;
	t_vector	axis;
	t_vertex	ctr;
	t_plane		top;
	t_plane		base;
	float		diameter;
	float		rim_dist;
	float		height;
	float		radius;
	float		radius_sqrd;
	float		ctr_cam_dot_norm;
	float		ctr_cam_dot_norm_sqrd;
}	t_cyl;

typedef struct s_sphere
{
	t_vector	cam_ctr_vec;
	t_vector	ctr_cam_vec;
	t_vertex	ctr;
	float		diameter;
	float		radius;
	float		radius_sqrd;
	float		ctr_cam_sqlen;
	float		trinomial_c;
}	t_sphere;

typedef struct s_cone
{
	t_vector	cam_ctr_vec;
	t_vector	ctr_cam_vec;
	t_vector	axis;
	t_vertex	ctr;
	t_plane		top;
	float		ctr_cam_dot_norm;
	float		ctr_cam_dot_norm_sqrd;
	float		ctr_angle;
	float		ctr_half_angle;
	float		ctr_half_angle_tan;
	float		ctr_half_angle_tan_sqrd;
	float		ctr_half_angle_tan_sqrd_plus_one;
	float		ctr_half_angle_tan_sqrd_plus_one_times_ctr_cam_dot_norm;
	float		ctr_half_angle_tan_sqrd_plus_one_times_ctr_cam_dot_norm_sqrd;
	float		trinomial_c;
	float		slant_len;
	float		slant_angle;
	float		diameter;
	float		height;
	float		radius;
}	t_cone;

typedef struct s_a_light
{
	t_color	color;
	float	ratio;
}	t_a_light;

typedef struct s_d_light
{
	t_vector	dir;
	t_color		color;
	float		bright;
}	t_d_light;

typedef struct s_cam
{
	unsigned int	fov;
	t_vector		dir;
	t_vertex		pos;
}	t_cam;

typedef struct s_s_light
{
	t_vertex	pos;
	t_color		color;
	float		bright;
}	t_s_light;

typedef union u_shape
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cone		*cone;
	t_cyl		*cyl;
}	t_shape;

typedef struct s_obj
{
	unsigned int	gloss;
	unsigned int	refness;
	struct s_obj	*next;
	t_vertex		*ctr;
	t_color			color;
	t_shape			shape;
	t_image			*stub_render_image;
	t_image			*full_render_image;
	t_image			*render_image_pointer;
	t_fill			fill;
	t_surface		surface;
	char			type;
	char			id;
	int				hit[S_HEIGHT][S_WIDTH];
}	t_obj;

typedef union u_src
{
	t_s_light	*spot;
	t_a_light	*amb;
	t_d_light	*dir;
}	t_src;

typedef struct s_lux
{
	struct s_lux	*next;
	float			dist;
	float			bright;
	t_color			color;
	t_src			src;
	char			type;
}	t_lux;

typedef struct s_scene
{
	struct s_cam	*cam;
	t_lux			*lux;
	t_obj			*obj;
	char			nb_obj;
}	t_scene;

void	set_cyl_vars(t_cyl *cyl, t_data *dt);
void	set_cyl_cam_vars(t_cyl *cyl, t_vertex cam_pos);
void	set_cone_vars(t_cone *cone, t_data *dt);
void	set_cone_cam_vars(t_cone *cone, t_vertex cam_pos);
void	set_sphere_vars(t_sphere *sphere, t_data *dt);
void	set_sphere_cam_vars(t_sphere *sphere, t_vertex cam_pos);
void	set_plane_vars(t_plane *plane, t_data *dt);
void	set_plane_cam_vars(t_plane *plane, t_vertex cam_pos);
void	set_cam_vars(t_data *dt, t_vertex cam_pos);
void	set_vars(t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*   SET utilities                                                            */
/*                                                                            */
/* ************************************************************************** */
void	next_object(t_obj **obj);
void	next_light(t_lux **light);
void	float_wrap(float *address, float min, float max);
void	uint_wrap(unsigned int *address, unsigned int min, unsigned int max);
void	range_wrap_scene(t_scene *scene);
void	range_wrap_cam(t_cam *cam);
void	range_wrap_objects(t_scene *scene);
void	range_wrap_lights(t_scene *scene);
void	range_wrap_light_commons(t_lux *light);
void	range_wrap_dir(t_d_light *dir);
void	range_wrap_object_commons(t_obj *object);
void	range_wrap_cone(t_cone *cone);
void	range_wrap_cyl(t_cyl *cyl);
void	range_wrap_sphere(t_sphere *sphere);
void	range_wrap_plane(t_plane *plane);
int		new_lux(t_scene *scene, int type);
int		new_obj(t_scene *scene, int type);

#endif
