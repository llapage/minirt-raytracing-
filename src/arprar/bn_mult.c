/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:46:58 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 08:33:29 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

static char	*do_mult(char *a, char *b, char *c)
{
	size_t	i;
	size_t	j;
	size_t	len_a;
	size_t	len_b;
	size_t	len_c;

	bn_clr(c);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	len_c = ft_strlen(c);
	i = 0;
	while (i < len_a)
	{
		j = 0;
		while (j < len_b)
		{
			if (bn_put(c, len_c - 1 - i - j,
					(a[len_a - 1 - i] - '0') * (b[len_b - 1 - j] - '0')))
				return (NULL);
			j++;
		}
		i++;
	}
	return (c);
}

char	*bn_mult(char *a, char *b, char **c)
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
	t_len = ft_max((bn_len(a) - a_dec),
			(bn_len(b) - b_dec)) + ft_max(a_dec, b_dec) + 1;
	t_len = ft_max(1, t_len);
	ta = bn_new(t_len, a); 
	tb = bn_new(t_len, b); 
	bn_norad(ta, a_dec);
	bn_norad(tb, b_dec);
	if (!*c)
		*c = bn_new(t_len, NULL);
	if (ft_strlen(*c) < t_len)
		return (NULL);
	bn_clr(*c);
	do_mult(ta, tb, *c); 
	return (free(ta), free(tb), bn_insrad(*c, a_dec + b_dec));
}

int	bn_pow(char *a, char *b, char *c)
{
	int		n;
	char	*t1;
	size_t	len;

	n = ft_atoi(b);
	bn_clr(c);
	if (!n)
		return (bn_set(c, "1"));
	if (n == 1)
		return (bn_set(c, a));
	len = ft_strlen(c);
	t1 = bn_new(len, a);
	if (!t1)
		return (-1);
	while (n-- > 1)
	{
		bn_mult(t1, "2", &c);
		ft_memcpy(t1, c, len);
		bn_clr(c);
	}
	ft_memcpy(c, t1, len);
	free(t1);
	return (0);
}
