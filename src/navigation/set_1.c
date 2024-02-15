/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 00:28:48 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	put_widget_background(t_data *dt)
{
	put_graphic_named("menu_bg", pix_l(S_WIDTH / 2 - 340, 0),
		dt->screen_image->image, dt);
	if (is_visible(&dt->nav[INFIELD_1]))
		put_graphic_named("input_bg", pix_l(S_WIDTH / 2 - 75, 
				S_HEIGHT / 2 - 66), dt->screen_image->image, dt);
}

void	display_screen_image(t_data *dt)
{
	put_render_image(dt);
	put_widget_background(dt);
	put_if_visible_all(dt, dt->screen_image->image);
	put_color_labels(dt, dt->screen_image->image);
	display_main_image(dt);
	put_screen_strings(dt);
}

void	push_screen_string(char *string, t_pixel position, unsigned int color, 
		t_data *dt)
{
	t_mlx_string	*mlx_str;
	t_list			*new_node;

	mlx_str = new_mlx_string(string, position, color);
	new_node = ft_lstnew(mlx_str);
	if (mlx_str == NULL || new_node == NULL)
	{
		free(string);
		free(mlx_str);
		free(new_node);
		exit_error("Malloc fail", dt);
	}
	ft_lstadd_front(&dt->screen_image->strings, new_node);
}

void	display_main_image(t_data *dt)
{
	mlx_put_image_to_window(dt->mlx, dt->win, dt->screen_image->image->ptr, 
		0, 0); 
}

void	repush_input_dialog_strings_and_display_screen_image(t_data *dt)
{
	clear_screen_strings(dt);
	push_input_dialog_strings(dt);
	display_screen_image(dt);
}
