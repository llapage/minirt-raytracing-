/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:52:13 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 21:39:12 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	do_select(t_nav *nav, t_data *dt)
{
	if (dt->nav_loc != NULL)
		unset_sub_menu(dt); 
	widget_loop(nav, dt);
	if (is_clickable(nav))
		execute_click(nav, dt);
	if (is_visible(nav))
		focus_item(nav);
	display_screen_image(dt);
}

int	select_widget(t_pixel ptr, t_data *dt)
{
	t_nav	*nav;

	nav = nav_under_pointer(ptr, dt);
	if (is_pressed(nav) == TRUE 
		&& is_active(nav) == TRUE)
	{
		do_select(nav, dt);
		return (1);
	}
	return (0);
}
