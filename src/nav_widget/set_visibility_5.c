/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visibility_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:51:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	hide_main_menu(t_data *dt)
{
	try_hide_item_and_siblings(&dt->nav[NAVRENDER]);
}

void	hide_input_dialog(t_data *dt)
{
	try_hide_item_and_siblings(&dt->nav[INFIELD_1]);
}

void	set_visible_main_menu(t_data *dt)
{
	set_visible_this_generation(&dt->nav[NAVRENDER], dt);
}
