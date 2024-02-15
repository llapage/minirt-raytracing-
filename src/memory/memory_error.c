/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:14:57 by llapage           #+#    #+#             */
/*   Updated: 2023/12/27 01:03:08 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

int	malloc_error(t_data *dt)
{
	printf("Error\nFatal: Memory allocation\n");
	free_data(dt);
	return (1);
}

void	exit_error(char *str, t_data *dt)
{
	printf("%s\n", str);
	free_data(dt);
	exit(1);
}
