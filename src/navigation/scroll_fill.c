/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:06:21 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:52:40 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	set_and_wrap_fill_type(t_nav *nav, int keycode)
{
	unsigned int	*fill_type;

	fill_type = nav->cont.uint_number;
	scroll_and_wrap_enum(fill_type, keycode, END_OF_FILL_ENUM);
}

static void	set_fill_graph_and_render(t_nav *nav, t_data *dt)
{
	set_fill_im(nav, dt);
	edit_mode(dt);
	render(dt);
}

void	scroll_fill(t_nav *nav, t_data *dt, int keycode)
{
	set_and_wrap_fill_type(nav, keycode);
	set_fill_graph_and_render(nav, dt);
}
