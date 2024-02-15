/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:32:37 by llapage           #+#    #+#             */
/*   Updated: 2023/11/15 23:58:51 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(const char *str, float *nbr)
{
	long long	decimals;
	char		**split_str;
	size_t		dec_len;
	float		b;

	(void)nbr;
	split_str = ft_split(str, '.');
	if (!split_str)
		return (-1);
	decimals = ft_atoll(split_str[0]);
	b = (float)decimals;
	*nbr = b;
	if (!split_str[1])
		dec_len = 0;
	else
		dec_len = ft_strlen(split_str[1]);
	*nbr += (float)ft_atoll(split_str[1]) / ft_pow(10, dec_len);
	if (str && str[0] == '-' && str[1] == '0')
		*nbr = -*nbr;
	free_s_arr(&split_str);
	return (0);
}
