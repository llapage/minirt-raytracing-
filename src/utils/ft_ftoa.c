/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:43:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 08:35:25 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftoa.h"

static char	*mk_s_dec(void)
{
	int		i;
	char	*s_dec;
	char	*t;

	t = NULL;
	s_dec = malloc(624 * sizeof(char));
	if (!s_dec)
		return (NULL);
	bn_nclr(s_dec, 624 - 1);
	i = 1;
	while (i < 25)
		s_dec[i++ *26 - 1] = '\0';
	bn_set(s_dec, "0.00000011920928955078125");
	i = -1;
	while (i++ < 22)
	{
		bn_mult(s_dec + (i * 26), "2", &t);
		bn_cln(&t);
		ft_memrcpy(s_dec + ((i + 1) * 26), t, bn_len(t));
		free(t);
		t = NULL;
	}
	free (t);
	return (s_dec);
}

static char	*mk_c_sif(uint32_t sif, char *s_dec)
{
	char	*c_sif;
	char	*t1;
	int		i;

	c_sif = bn_new(25, NULL);
	t1 = bn_new(26, NULL);
	if (!c_sif || !t1)
	{
		free(c_sif);
		free(t1);
		return (NULL);
	}
	i = -1;
	while (i++ < 23)
	{
		if (sif & (1 << i))
		{
			bn_add(s_dec + (i * 26), c_sif, t1);
			ft_memrcpy(c_sif, t1, bn_len(t1));
		}
	}
	free(t1);
	return (c_sif);
}

static char	*mk_t_exp_2(char *t1, char *t_exp, int inv)
{
	bn_pow("2", t1, t_exp);
	if (inv)
	{
		if (!bn_div("1", t_exp, &t1, 40))
		{
			free(t1);
			return (NULL);
		}
		ft_memrcpy(t_exp, t1, bn_len(t1));
	}
	free(t1);
	return (t_exp);
}

static char	*mk_t_exp(int exp)
{
	char	*t_exp;
	char	*t1;
	int		inv;

	inv = 0;
	t_exp = bn_new(50, NULL);
	if (exp == -127)
		return (t_exp);
	if (!t_exp)
		return (NULL);
	t1 = bn_new(50, NULL);
	if (exp < 0)
	{
		inv = 1;
		exp *= -1;
	}
	while (exp-- > 0)
	{
		bn_add(t1, "1", t_exp);
		ft_memrcpy(t1, t_exp, bn_len(t_exp));
	}
	return (mk_t_exp_2(t1, t_exp, inv));
}

char	*ft_ftoa(float f, int prec)
{
	char	*s_dec;
	char	*c_sif;
	char	*t_exp;
	char	*res;
	t_float	ft;

	ft = rd_float(f);
	s_dec = mk_s_dec();
	if (!s_dec)
		return (NULL);
	c_sif = mk_c_sif(ft.sif, s_dec);
	t_exp = mk_t_exp(ft.exp);
	res = bn_new(64, NULL);
	if (c_sif && t_exp && res)
		bn_mult(c_sif, t_exp, &res);
	free(c_sif);
	free(s_dec);
	free(t_exp);
	return (bn_rnd(&res, prec, ft.sig));
}
