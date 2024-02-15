/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 08:56:03 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

void	tilt(float angle, t_data *dt)
{
	dt->scene->cam->dir = rotate_x(dt->scene->cam->dir, angle);
}
