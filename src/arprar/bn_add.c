/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:45:44 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 18:34:56 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

static char	*do_add(char *a, char *b, char *c)
{
	size_t	i;
	size_t	len_a;
	size_t	len_b;
	size_t	len_c;
	int		n;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	len_c = ft_strlen(c);
	i = 0;
	while (i < len_c)
	{
		n = 0;
		if (i < len_a)
			n = a[len_a - 1 - i] - '0';
		if (i < len_b)
			n += b[len_b -1 - i] - '0';
		if (n && bn_put(c, len_c - 1 - i, n))
			return (NULL);
		i++;
	}
	return (c);
}

static void	pre_add(char *ta, char *tb, size_t a_dec, size_t b_dec)
{
	bn_norad(ta, a_dec);
	bn_norad(tb, b_dec);
	bn_pad(ta, b_dec - a_dec);
	bn_pad(tb, a_dec - b_dec);
}

char	*bn_add(char *a, char *b, char *c)
{
	size_t	a_dec;
	size_t	b_dec;
	size_t	t_len;
	char	*ta;
	char	*tb;

	if (!a || !b || !*a || !*b)
		return (NULL);
	a_dec = bn_decs(bn_trim(a));
	b_dec = bn_decs(bn_trim(b));
	t_len = ft_max(bn_len(a) - a_dec, bn_len(b) - b_dec)
		+ ft_max(a_dec, b_dec) + 1;
	t_len = ft_max(1, t_len);
	ta = bn_new(t_len, a);
	tb = bn_new(t_len, b);
	pre_add(ta, tb, a_dec, b_dec);
	if (!c)
		c = bn_new(t_len, NULL);
	if (ft_strlen(c) < t_len)
		return (NULL);
	bn_clr(c);
	do_add(ta, tb, c);
	free(ta);
	free(tb);
	return (bn_insrad(c, ft_max(a_dec, b_dec)));
}
