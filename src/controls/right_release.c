/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:58:47 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	right_release(t_pixel ptr, t_data *dt)
{
	if (dt->nav_loc != NULL)
	{
		unset_sub_menu(dt);
		display_screen_image(dt);
	}
	show_sub_menu(ptr, dt);
}
