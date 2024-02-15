/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:38:34 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 13:53:46 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	first_sub_line(t_data *dt)
{
	return (dt->px.y + dt->vp->b_offs);
}

int	first_sub_pixel(t_data *dt)
{
	return (dt->px.x);
}
