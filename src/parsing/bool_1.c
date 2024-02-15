/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:27:51 by llapage           #+#    #+#             */
/*   Updated: 2024/01/18 16:50:30 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	bad_int(char *str)
{
	if (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str && *str != '\n')
		return (TRUE);
	else
		return (FALSE);
}

int	bad_float(char *str)
{
	if (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str && *str == '.')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str)
		return (TRUE);
	else
		return (FALSE);
}

int	bad_float_coord(char **str)
{
	if (**str && (**str == '-' || **str == '+'))
		(*str)++;
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (**str && **str == '.')
		(*str)++;
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (**str && **str != ',')
		return (TRUE);
	if (**str)
		(*str)++;
	if (!(**str))
		return (TRUE);
	else
		return (FALSE);
}

int	bad_coord(char *element)
{
	if (bad_float_coord(&element))
		return (TRUE);
	if (bad_float_coord(&element))
		return (TRUE);
	if (bad_float(element))
		return (TRUE);
	else
		return (FALSE);
}
