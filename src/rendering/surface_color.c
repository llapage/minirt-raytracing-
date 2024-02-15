/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:52:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 22:48:47 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static t_color	color_at_image(t_hit *hit, t_data *dt);
static t_color	checker_at(t_vertex p, int width, int height, t_color color);

t_color	surface_color(t_hit *hit, t_data *dt)
{
	t_color	color;

	if (hit->obj->fill == SOLID_FILL)
		color = hit->obj->color;
	else if (hit->obj->fill == PERLIN_FILL)
		color = hit->obj->color;
	else if (hit->obj->fill == CHECKER_FILL)
		color = checker_at(surface_map(hit), 48, 24, hit->obj->color);
	else
		color = color_at_image(hit, dt);
	return (color);
}

static t_color	color_at_image(t_hit *hit, t_data *dt)
{
	char	*image;
	t_color	color;

	if (hit->obj->fill == EARTH_FILL)
		image = "earth_erp";
	else if (hit->obj->fill == MARS_FILL)
		image = "mars_erp";
	else if (hit->obj->fill == VENUS_FILL)
		image = "venus_erp";
	else if (hit->obj->fill == SUN_FILL)
		image = "sun_erp";
	else if (hit->obj->fill == MOON_FILL)
		image = "moon_erp";
	else
		image = NULL;
	color = color_at(surface_map(hit), get_graphic(dt, image));
	return (color);
}

static t_color	checker_at(t_vertex p, int width, int height, t_color color)
{
	int	intu;
	int	intv;

	if (p.x < 0)
		p.x = -p.x + 1.0 / (float)width;
	if (p.y < 0)
		p.y = -p.y + 1.0 / (float)height;
	intu = p.x * width;
	intv = p.y * height;
	if ((intu + intv) % 2)
		return (color);
	return (get_color(0, 0, 0));
}
