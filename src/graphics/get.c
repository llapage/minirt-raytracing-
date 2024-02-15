/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:45:36 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:35:13 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_graphic	*get_graphic(t_data *dt, char *title)
{
	t_graphic	*gr;

	if (!title)
		return (NULL);
	gr = dt->graph;
	while (gr && ft_strcmp(gr->title, title))
		gr = gr->next;
	return (gr);
}

t_color	color_at(t_vertex p, t_graphic *gr)
{
	t_pixel	pixel;
	t_color	color;

	pixel = to_int_pixel(p, gr);
	color = gr->pixel_color[pixel.y * gr->width + pixel.x];
	return (color);
}

t_pixel	to_int_pixel(t_vertex uip, t_graphic *gr)
{
	t_pixel	pixel;

	pixel.x = uip.x * gr->width;
	pixel.y = uip.y * gr->height;
	return (pixel);
}
