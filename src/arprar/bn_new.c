/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:46:16 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 18:35:20 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arprar.h"

int	bn_set(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;
	size_t	b_len_b;
	size_t	i;

	bn_clr(a);
	b_len_b = bn_len(b);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (b_len_b > len_a)
		return (-1);
	i = 0;
	while (i < b_len_b)
	{
		a[len_a - 1 - i] = b[len_b - 1 - i];
		i++;
	}
	return (0);
}

int	bn_val(char *a)
{
	char	*s;
	int		rad;

	rad = 0;
	s = a;
	if (!s || !*s || !ft_isdigit(*s++))
		return (0);
	while (*s)
	{
		if (*s == '.' && !rad)
			rad++;
		else if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

char	*bn_new(int len, char *in)
{
	char	*c;

	if (len < 1)
		len = ft_strlen(in);
	if (!len || (in && !bn_val(in)))
		return (NULL);
	c = malloc(len + 1 * sizeof(char));
	if (!c)
		return (NULL);
	c[len] = '\0';
	bn_nclr(c, len);
	if (in)
		bn_set(c, in);
	return (c);
}
