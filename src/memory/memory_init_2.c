/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memeory_init_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:54:43 by llapage           #+#    #+#             */
/*   Updated: 2024/01/22 15:56:14 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void	nav_init(t_data *dt)
{
	int	i;

	i = 0;
	while (i < 30)
	{
		dt->nav[i].child = NULL;
		dt->nav[i].sibling = NULL;
		dt->nav[i++].parent = NULL;
	}
}
