/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:08:08 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 00:03:22 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	execute_click(t_nav *nav, t_data *dt)
{
	nav->act(nav, dt);
}

void	execute_scroll(t_nav *nav, t_data *dt, int keycode)
{
	nav->scr(nav, dt, keycode);
}
