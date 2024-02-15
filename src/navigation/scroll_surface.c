/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_surface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:06:21 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:53:56 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	set_and_wrap_surface_type(t_nav *nav, int keycode)
{
	unsigned int	*surface_type;

	surface_type = nav->cont.uint_number;
	scroll_and_wrap_enum(surface_type, keycode, END_OF_SURFACE_ENUM);
}

static void	set_surface_graph_and_render(t_nav *nav, t_data *dt)
{
	set_surface_im(nav, dt);
	edit_mode(dt);
	render(dt);
}

void	scroll_surface(t_nav *nav, t_data *dt, int keycode)
{
	set_and_wrap_surface_type(nav, keycode);
	set_surface_graph_and_render(nav, dt);
}
