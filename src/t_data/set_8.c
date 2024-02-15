/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 09:00:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	save_cam_and_vp_state(t_data *dt)
{
	save_state(dt->scene->cam, CAM, dt);
	save_state(dt->vp, VP, dt);
}
