/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:00:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 16:07:40 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "navigation.h"
# include "graphics.h"
# include "graphics.h"
# include "parsing.h"
# include "render.h"
# include "t_data.h"
# include "scene.h"
# include "gui.h"

int		loop(void *data);
void	launch(t_data *dt);
void	execute_button_press(t_data *dt);
void	execute_button_release(t_data *dt);
void	execute_mouse_move(t_data *dt);
void	execute_key_press(t_data *dt);

#endif
