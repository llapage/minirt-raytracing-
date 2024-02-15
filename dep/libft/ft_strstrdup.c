/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 02:27:57 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:04:46 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strstrdup(const char **src)
{
	char	**new_strstr;
	size_t	len;
	size_t	i;

	len = ft_strstrlen(src);
	new_strstr = malloc((len + 1) * sizeof(char *));
	new_strstr[len] = 0x00;
	i = 0;
	while (i < len)
	{
		new_strstr[i] = ft_strdup(src[i]);
		i++;
		if (!(new_strstr))
		{
			while (i-- != 0)
				free(new_strstr[i]);
			free(new_strstr);
			return (NULL);
		}
	}
	return (new_strstr);
}
