/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_main_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:38:34 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/20 20:01:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	put_color_in_main_image(t_hit *hit, t_data *dt)
{
	int		counter;

	set(&counter);
	while (there_are_more_sub_pixels(counter, dt))
	{
		put_color_in_main_image_pixel(hit, counter, dt);
		increase(&counter);
	}
}
