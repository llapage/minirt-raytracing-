/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:17:05 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:46:19 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	export_out(t_nav *nav, t_data *dt)
{
	(void)nav;
	if (tiff_export((uint8_t *)dt->render_image_pointer->data_addr,
			S_WIDTH, S_HEIGHT) == -1)
		exit_error("export failure", dt);
}
