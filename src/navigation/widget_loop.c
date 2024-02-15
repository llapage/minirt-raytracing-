/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:16:27 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:03:16 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	widget_loop(t_nav *nav, t_data *dt)
{
	int	was_focused;

	(void)nav;
	was_focused = reset_widgets(dt);
	if (was_focused)
		display_screen_image(dt);
}
