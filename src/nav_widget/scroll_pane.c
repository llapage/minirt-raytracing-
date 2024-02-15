/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_pane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 15:09:23 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	do_scroll_pane(t_nav *nav, t_nav *bottom, int keycode)
{
	if (keycode == SCROLL_UP_BUTTON)
		scroll_pane_up(nav, bottom);
	else
		scroll_pane_down(nav, bottom);
}

void	scroll_pane(t_nav *nav, t_data *dt, int keycode)
{
	t_nav	*bottom;

	(void)dt;
	bottom = pane_bottom_element(nav);
	do_scroll_pane(nav, bottom, keycode);
}
