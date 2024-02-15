/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:41:50 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/25 21:40:59 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

int	bn_eql(char *a, char *b)
{
	if (!bn_smlr(a, b) && !bn_smlr(b, a))
		return (1);
	return (0);
}

int	bn_iszro(char *a)
{
	while (*a && *a == '0')
		a++;
	if (*a)
		return (0);
	return (1);
}

char	*bn_shft_ins(char *a, size_t off, int n)
{
	size_t	i;

	i = 0;
	if (off > ft_strlen(a))
		return (NULL);
	while (i + 1 < off)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = n + '0';
	return (a);
}

int	bn_line(char *a, char *b, char **ta, char **tb)
{
	size_t	a_dec;
	size_t	b_dec;
	size_t	len_t;

	a_dec = bn_decs(bn_trim(a));
	b_dec = bn_decs(bn_trim(b));
	len_t = bn_len(a) + bn_len(b);
	len_t = ft_max(1, len_t);
	*ta = bn_new(len_t, a);
	*tb = bn_new(len_t, b);
	if (!*ta || !*tb)
	{
		free(*ta);
		free(*tb);
		return (0);
	}
	bn_norad(*ta, a_dec);
	bn_norad(*tb, b_dec);
	bn_pad(*ta, b_dec - a_dec); 
	bn_pad(*tb, a_dec - b_dec);
	return (len_t);
}

int	bn_smlr(char *a, char *b)
{
	char	*ta;
	char	*tb;
	size_t	len_t;
	int		smlr;
	size_t	i;

	len_t = bn_line(a, b, &ta, &tb);
	smlr = -1;
	i = 0;
	if (!len_t)
		return (-1);
	while (i < len_t && smlr == -1)
	{
		if (ta[i] < tb[i])
			smlr = 1;
		else if (ta[i] > tb[i])
			smlr = 0;
		i++;
	}
	free(ta);
	free(tb);
	return (ft_max(0, smlr));
}
