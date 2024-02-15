/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:24:14 by llapage           #+#    #+#             */
/*   Updated: 2023/12/29 22:57:56 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <stdlib.h>
# include "keycodes.h"
# include "history.h"
# include "params.h"
# include "vector.h"
# include "t_data.h"
# include "scene.h"
# include "defs.h"
# include "mlx.h"
# include "image.h"

t_vector	multiply_matrix(t_vector src_v, float m[3][3]);
t_vector	rotate_x(t_vector src_v, float amplitude);
t_vector	rotate_y(t_vector src_v, float amplitude);
t_vector	rotate_z(t_vector src_v, float amplitude);
void		obj_translate(t_pixel ptr, t_hit ht, t_data *dt);
void		scale(t_data *dt, int keycode, t_pixel ptr);
void		scale_height_cyl(t_data *dt, float ratio);
void		scale_width_cyl(t_data *dt, float ratio);
void		scale_sphere(t_data *dt, float ratio);
void		transform_sphere(t_data *dt);
void		transform_obj(t_data *dt);
void		move_cam_e(t_data *data);
void		move_cam_q(t_data *data);
void		rotate_camera(t_pixel displacement, t_data *data);
void		pan(float angle, t_data *data);
void		tilt(float angle, t_data *data);

#endif
