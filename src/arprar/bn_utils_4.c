/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:41 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 08:25:27 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

size_t	bn_len(char *a)
{
	size_t	len;

	if (!a)
		return (0);
	len = ft_strlen(a);
	while (*a && *a == '0')
	{
		a++;
		len--;
	}
	if (*a && *a == '.')
		len++;
	return (len);
}

int	bn_tke(char *a, int pos, char dig)
{
	if (dig <= 0)
		return (0);
	if (pos < 0)
		return (-1);
	bn_tke(a, pos - 1, dig - a[pos] - '0');
	a[pos] = ft_max(0, a[pos] - dig);
	return (0);
}

void	bn_clr(char *a)
{
	while (*a)
		*a++ = '0';
}

void	bn_nclr(char *a, size_t n)
{
	while (n-- > 0)
		*a++ = '0';
}

char	*bn_strt(char *a)
{
	while (*a && *a == '0')
		a++;
	return (a);
}
