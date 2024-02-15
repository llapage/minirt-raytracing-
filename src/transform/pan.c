/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 21:17:20 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

void	pan(float angle, t_data *dt)
{
	dt->scene->cam->dir = rotate_y(dt->scene->cam->dir, angle);
}
