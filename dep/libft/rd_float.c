/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:33:50 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:55:54 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_float	rd_float(float f)
{
	t_float		ft;
	int			i;
	uint32_t	exp_b;

	ft.u_val.fl = f;
	ft.sif = ft.u_val.ui;
	exp_b = 0;
	i = 23;
	while (i < 31)
		exp_b |= (1 << i++) & ft.u_val.ui;
	ft.sig = ft.u_val.ui >> 31;
	while (i > 22)
		ft.sif &= ~(1 << i--);
	i++;
	ft.sif |= (1 << i);
	exp_b >>= i;
	ft.exp = exp_b - 127;
	return (ft);
}
