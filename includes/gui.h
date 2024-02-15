/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:48:47 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 21:32:10 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "memory.h"
# include "viewport.h"
# include "os_def.h"
# include "t_data.h"
# include "scene.h"
# include "controls.h"
# include "image.h"

typedef struct s_cam	t_cam;
typedef struct s_obj	t_obj;

void	show_str(t_data *dt, char *s, t_pixel px, int color);
void	move_cam(int keycode, t_data *data);
void	clear_image(t_image *img, t_data *dt);
void	clear_stub_images(t_data *dt);
void	show_obj(t_data *dt);
void	point_to_stub_render_images(t_data *dt);
void	point_to_full_render_images(t_data *dt);
int		gui_init(t_data *data);
int		exit_minirt(t_data *dt);

#endif
