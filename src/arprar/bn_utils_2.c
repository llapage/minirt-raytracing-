/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:47:54 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/25 21:36:37 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

size_t	bn_decs(char *a)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(a);
	while (i < len)
	{
		if (a[len - 1 - i] == '.')
			return (i);
		i++;
	}
	return (0);
}

char	*bn_pad(char *a, size_t n)
{
	size_t	len;

	len = ft_strlen(a);
	if (len < n)
		return (NULL);
	while (n-- > 0)
		bn_shft_ins(a, len, 0);
	return (a);
}

char	*bn_norad(char *a, size_t decs)
{
	size_t	len;

	len = ft_strlen(a);
	if (!decs)
		return (a);
	return (bn_shft_rt(a, len - decs));
}

char	*bn_insrad(char *a, size_t decs)
{
	size_t	len;

	if (!decs)
		return (a);
	len = ft_strlen(a);
	return (bn_shft_ins(a, len - decs, '.' - '0'));
}

int	bn_put(char *a, int pos, char dig)
{
	int	val;

	if (!dig)
		return (0);
	if (pos < 0)
		return (-1);
	val = a[pos] - '0' + dig;
	a[pos] = val % 10 + '0';
	bn_put(a, pos - 1, val / 10);
	return (0);
}
