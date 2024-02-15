/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:52:30 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	set_render_image_to(t_image **img, t_data *dt)
{
	set_image_pointer_to_pointer(&dt->screen_image->render_image, img);
}

void	put_render_image(t_data *dt)
{
	copy_image(dt->screen_image->image, *dt->screen_image->render_image);
}

void	put_screen_strings(t_data *dt)
{
	put_mlx_string_list(dt->mlx, dt->win, dt->screen_image->strings);
}

void	clear_screen_strings(t_data *dt)
{
	ft_lstclear(&dt->screen_image->strings, free_mlx_string);
}
