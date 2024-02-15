/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_subt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:39:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/11/25 21:44:57 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

static int	bn_s_ver(char *a, char *b, char **c, char **t1)
{
	*t1 = bn_new(0, a);
	if (!*t1 || bn_smlr(a, b))
	{
		free(*t1);
		free(*c);
		*c = NULL;
		return (-1);
	}
	return (0);
}

static char	*do_subt(char *a, char *b, char *c)
{
	char	*t1;
	size_t	len_a;
	size_t	len_b;
	size_t	len_c;
	size_t	i;

	if (bn_s_ver(a, b, &c, &t1))
		return (NULL);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	len_c = ft_strlen(c);
	i = 0;
	while (i < len_a)
	{
		if (t1[len_a - 1 - i] < b[len_b - 1 - i])
		{
			c[len_c - 1 - i] = 10 + '0' + t1[len_a - 1 - i] - b[len_b - 1 - i];
			bn_tke(t1, len_a - 1 - 1 - i, 1);
		}
		else
			c[len_c - 1 - i] = t1[len_a - 1 - i] - b[len_b - 1 - i] + '0';
		i++;
	}
	free(t1);
	return (c);
}

static void	pre_subt(char *ta, char *tb, size_t *a_dec, size_t *b_dec)
{
	bn_norad(ta, *a_dec);
	bn_norad(tb, *b_dec);
	if (bn_smlr(ta, tb))
	{
		(*a_dec)++;
		(*b_dec)++;
		bn_pad(ta, ft_max((*b_dec - *a_dec), 0) + 1);
		bn_pad(tb, ft_max((*a_dec - *b_dec), 0) + 1);
	}
	else
	{
		bn_pad(ta, ft_max((*b_dec - *a_dec), 0));
		bn_pad(tb, ft_max((*a_dec - *b_dec), 0));
	}
}

char	*bn_subt(char *a, char *b, char *c)
{
	size_t	a_dec;
	size_t	b_dec;
	size_t	t_len;
	char	*ta;
	char	*tb;

	if (!a || !b || !*a || !*b || bn_smlr(a, b))
		return (NULL);
	a_dec = bn_decs(bn_trim(a));
	b_dec = bn_decs(bn_trim(b));
	t_len = ft_max(bn_len(a) - a_dec, bn_len(b) - b_dec) + ft_max(a_dec, b_dec);
	t_len = ft_max(1, t_len);
	ta = bn_new(t_len + 2, a); 
	tb = bn_new(t_len + 2, b); 
	pre_subt(ta, tb, &a_dec, &b_dec);
	if (!c)
		c = bn_new(t_len + 2, NULL);
	if (ft_strlen(c) < t_len + 2)
		return (NULL);
	bn_clr(c);
	if (!do_subt(ta, tb, c))
		return (NULL);
	free(ta);
	free(tb);
	return (bn_insrad(c, ft_max(a_dec, b_dec)));
}
