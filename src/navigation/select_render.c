/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:10:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 08:18:15 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	select_render(t_nav *nav, t_data *dt)
{
	(void)nav;
	if (in_edit_mode(dt))
	{
		default_mode(dt);
		clear_history(dt);
		render(dt);
	}
}
