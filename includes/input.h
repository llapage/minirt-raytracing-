/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:22 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:49:27 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <math.h>
# include <stdlib.h>
# include "nav_widget.h"
# include "render.h"
# include "ftoa.h"
# include "gui.h"

# define ASCII_ESC 27

void	user_input(int keycode, t_nav *nav, t_data *dt);
void	update_float_value(t_nav *nav, char value, t_data *dt);
void	update_storage(t_nav *nav, char value, t_data *dt);
void	cancel_input(t_nav *nav, t_data *dt);
void	confirm_input(t_nav *nav, t_data *dt);
void	start_input(t_nav *nav, t_data *dt);
void	input_mode_init(t_nav *nav, t_data *dt);
void	input_dialog_link_item(t_nav *nav, t_data *dt);
void	push_input_dialog_strings(t_data *dt);
char	key_to_char(int keycode);

#endif
