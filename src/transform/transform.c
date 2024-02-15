/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:22:24 by llapage           #+#    #+#             */
/*   Updated: 2023/11/26 19:35:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/transform.h"

void	transform_obj(t_data *dt)
{
	if (dt->curr_obj->type == SPHERE)
		transform_sphere(dt);
	else
		display_main_image(dt);
}
