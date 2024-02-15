/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/18 16:12:04 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	left_release(t_pixel ptr, t_data *dt)
{
	if (drop_object(ptr, dt) == 0)
		select_widget(ptr, dt);
}
