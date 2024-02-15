/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bool_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:52:06 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 10:45:42 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersect.h"

int	is_insignificant(float a)
{
	if (a < -FLT_MIN || a > FLT_MIN)
		return (FALSE);
	return (TRUE);
}

int	depth_tracing(void)
{
	if (DEPTH_RAYS != 0)
		return (TRUE);
	return (FALSE);
}
