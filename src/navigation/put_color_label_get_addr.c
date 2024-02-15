/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_label_get_addr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:50:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/24 18:36:54 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static t_pixel	pix_translate(t_pixel a, t_pixel b)
{
	t_pixel	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

char	*put_color_label_get_addr(t_pixel px, t_nav *nav, t_image *img)
{
	t_pixel	top_left;
	char	*addr;
	int		u_offset;
	int		v_offset;

	top_left = pix_translate(nav->gp, pix_l(120, 10));
	u_offset = (top_left.x + px.x) * img->size_pixel;
	v_offset = (top_left.y + px.y) * img->size_line;
	addr = img->data_addr + u_offset + v_offset;
	return (addr);
}
