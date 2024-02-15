/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:42 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 15:54:18 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/image.h"

int	out_of_bounds(t_pixel pixel)
{
	if (within_area(pixel, pix_l(0, 0),
			pix_l(S_WIDTH - 1, S_HEIGHT - 1)) == FALSE)
		return (TRUE);
	else
		return (FALSE);
}

int	within_area(t_pixel ptr, t_pixel top_left, t_pixel bottom_right)
{
	if (ptr.x < top_left.x
		|| ptr.y < top_left.y
		|| ptr.x > bottom_right.x
		|| ptr.y > bottom_right.y)
		return (FALSE);
	else
		return (TRUE);
}
