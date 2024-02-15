/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:40:51 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/25 21:20:42 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, void *src, size_t n)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	if (!dst || !src || n > ft_strlen(dst))
		return (dst);
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = 0;
	while (i++ < len_s && n--)
		*(char *)(dst + len_d - i) = *(char *)(src + len_s - i);
	return (dst);
}
