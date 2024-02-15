/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:29:17 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 08:34:53 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

static char	*bn_rnd_t(char **a, int prec, int sign)
{
	char	*t;
	int		d_decs;

	d_decs = (int)bn_decs(*a) - prec;
	t = bn_new(sign + bn_len(*a) + prec + 1 + (prec > 0), *a);
	free(*a);
	if (!t) 
		return (NULL);
	bn_norad(t, bn_decs(t));
	if (d_decs > 0)
	{
		while (d_decs-- > 1)
			bn_shft_rt(t, ft_strlen(t));
		if (t[ft_strlen(t) - 1] > '4') 
			bn_put(t, ft_strlen(t) - 2, 1);
		bn_shft_rt(t, ft_strlen(t));
	}
	while (d_decs < 0)
	{
		bn_shft_ins(t, ft_strlen(t), 0);
		d_decs++;
	}
	bn_insrad(t, prec);
	return (t);
}

char	*bn_rnd(char **a, int prec, int sign)
{
	char	*t;
	int		i;

	if (prec < 0)
		prec = 0;
	t = bn_rnd_t(a, prec, sign);
	if (!t)
		return (NULL);
	i = 0;
	while (t[i] == '0')
		i++;
	if (t[i] == '.')
		i--;
	*a = bn_new(sign + ft_strlen(t) - i, t);
	free(t);
	if (*a && sign)
		*a[0] = '-';
	return (*a);
}

char	*bn_shft_rt(char *a, size_t off)
{
	if (off > ft_strlen(a))
		return (NULL);
	while (off-- > 1)
		a[off] = a[off - 1];
	a[0] = '0';
	return (a);
}

char	*bn_trim(char *a)
{
	size_t	len;
	size_t	i;

	if (!a || !*a)
		return (NULL);
	if (!ft_strchr(a, '.'))
		return (a);
	len = ft_strlen(a);
	i = len;
	while (i-- && (a[len - 1] == '0' || a[len - 1] == '.'))
	{
		bn_shft_rt(a, len);
		if (a[len - 1] == '.')
		{
			bn_shft_rt(a, len);
			break ;
		}
	}
	return (a);
}

char	*bn_cln(char **a)
{
	char	*b;

	bn_trim(*a);
	b = bn_new(ft_max(bn_len(*a), 1), *a);
	free(*a);
	*a = NULL;
	*a = b;
	return (*a);
}
