/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:45:45 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	scroll_and_refocus(t_pixel ptr, t_nav *nav, t_data *dt, 
		int keycode)
{
	execute_scroll(nav, dt, keycode);
	focus_widget(ptr, dt);
}

int	scroll_widget(t_pixel ptr, t_data *dt, int keycode)
{
	t_nav	*nav;

	nav = nav_under_pointer(ptr, dt);
	if (is_scrollable(nav))
	{
		scroll_and_refocus(ptr, nav, dt, keycode);
		return (1);
	}
	return (0);
}
