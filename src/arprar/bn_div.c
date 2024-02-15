/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:35:55 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 22:38:05 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

static int	dv_alloc(char **t1, char **t2, char **a_cpy, int *prec)
{
	*t1 = NULL;
	*t2 = NULL;
	if (*a_cpy)
	{
		*t1 = bn_new(ft_strlen(*a_cpy), NULL);
		*t2 = bn_new(ft_strlen(*a_cpy), NULL);
	}
	*prec = -1;
	if (!*t1 || !*t2 || !*a_cpy)
	{
		free(*t1);
		free(*t2);
		free(*a_cpy);
		return (-1);
	}
	return (0);
}

static int	bn_ver(char *b, char *t1, char *t2, char *a_cpy)
{
	bn_subt(t2, b, t1);
	bn_subt(a_cpy, t1, t2);
	ft_memcpy(a_cpy, t2, ft_strlen(t2));
	if (bn_iszro(a_cpy))
		return (1);
	bn_shft_ins(a_cpy, ft_strlen(a_cpy), 0);
	return (0);
}

static char	*do_div(char *a, char *b, char *c, int *prec)
{
	char	*t1;
	char	*t2;
	char	*a_cpy;
	int		i;

	i = *prec;
	a_cpy = bn_new(ft_strlen(b), a); 
	if (dv_alloc(&t1, &t2, &a_cpy, prec))
		return (NULL);
	while (i--)
	{
		bn_shft_ins(c, ft_strlen(c), 0);
		ft_memcpy(t1, b, ft_strlen(b));
		ft_memcpy(t2, b, ft_strlen(b));
		while (bn_smlr(t2, a_cpy) || bn_eql(t2, a_cpy))
		{
			bn_put(c, ft_strlen(c) - 1, 1);
			bn_add(t1, b, t2);
			ft_memcpy(t1, t2, ft_strlen(b));
		}
		(*prec)++;
		if (bn_ver(b, t1, t2, a_cpy))
			break ;
	}
	return (free(t1), free(t2), free(a_cpy), c);
}

static int	c_dec(size_t a_dec, size_t b_dec, char *c, int prec)
{
	int	i;
	int	j;

	i = ft_max(0, (int)a_dec - (int)b_dec);
	j = ft_max(0, (int)b_dec - (int)a_dec);
	while (j-- > 0)
		bn_shft_ins(c, ft_strlen(c), 0);
	return (i + prec);
}

char	*bn_div(char *a, char *b, char **c, int prec)
{
	size_t	a_dec;
	size_t	b_dec;
	int		t_len;
	char	*ta;
	char	*tb;

	if (!a || !b || !*a || !*b || bn_eql(b, "0"))
		return (NULL);
	a_dec = bn_decs(bn_trim(a));
	b_dec = bn_decs(bn_trim(b));
	t_len = bn_len(a) + bn_len(b) + prec + 1;
	ta = bn_new(t_len, a);
	tb = bn_new(t_len, b); 
	bn_norad(ta, a_dec);
	bn_norad(tb, b_dec);
	if (c && *c)
		free(*c);
	*c = bn_new(t_len, NULL);
	if (!*c)
		return (NULL);
	do_div(ta, tb, *c, &prec); 
	free(ta);
	free(tb);
	return (bn_insrad(*c, c_dec(a_dec, b_dec, *c, prec)));
}
