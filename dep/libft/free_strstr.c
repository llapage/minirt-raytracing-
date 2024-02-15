/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:54:37 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/15 23:57:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_strstr(char ***strstr, size_t len)
{
	if (!(*strstr))
		return ;
	while (len-- != 0)
	{
		free((*strstr)[len]);
		(*strstr)[len] = NULL;
	}
	free(*strstr);
	*strstr = NULL;
}
