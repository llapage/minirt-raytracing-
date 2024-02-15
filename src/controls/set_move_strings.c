/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:12:26 by llapage           #+#    #+#             */
/*   Updated: 2024/01/21 14:35:30 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controls.h"

void	set_move_strings(t_data *dt)
{
	char	*tmp;
	int		x;
	int		y;

	x = dt->x_diff;
	y = dt->y_diff;
	dt->coord_msg[X] = ft_strdup("x: ");
	if (x > 0)
		dt->coord_msg[X] = ft_strfjoin(dt->coord_msg[X], "+");
	tmp = ft_itoa(x);
	if (!dt->coord_msg[X] || !tmp)
		exit(malloc_error(dt));
	dt->coord_msg[X] = ft_strfjoin(dt->coord_msg[X], tmp);
	free(tmp);
	dt->coord_msg[Y] = ft_strdup("y: ");
	if (y > 0)
		dt->coord_msg[Y] = ft_strfjoin(dt->coord_msg[Y], "+");
	tmp = ft_itoa(y);
	if (!dt->coord_msg[Y] || !tmp)
		exit(malloc_error(dt));
	dt->coord_msg[Y] = ft_strfjoin(dt->coord_msg[Y], tmp);
	free(tmp);
	if (!dt->coord_msg[X] || !dt->coord_msg[Y])
		exit(malloc_error(dt));
}
