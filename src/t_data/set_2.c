/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 01:50:03 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	set_next_line(t_data *dt)
{
	dt->px.y += dt->sub_samples;
}

void	set_next_pixel(t_data *dt)
{
	dt->px.x += dt->sub_samples;
}

void	set_first_super_line(t_data *dt)
{
	dt->sub_line = 0;
}

void	set_first_super_pixel(t_data *dt)
{
	dt->sub_col = 0;
}

void	set_next_super_pixel(t_data *dt)
{
	(dt->sub_col)++;
}
