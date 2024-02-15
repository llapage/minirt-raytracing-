/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:20:58 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:59:13 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

int	press_widget(t_pixel ptr, t_data *dt)
{
	t_nav	*nav;

	nav = nav_under_pointer(ptr, dt);
	if (nav != NULL
		&& is_pressed(nav) == FALSE
		&& image_locked(nav) == FALSE)
	{
		press_item(nav);
		display_screen_image(dt);
		return (1);
	}
	else if (nav == NULL
		&& dt->nav_loc != NULL)
	{
		unset_sub_menu(dt);
		display_screen_image(dt);
	}
	return (0);
}
