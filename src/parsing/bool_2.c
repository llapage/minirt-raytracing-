/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:27:51 by llapage           #+#    #+#             */
/*   Updated: 2023/11/09 21:16:40 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	bad_rgb(char *element)
{
	if (!ft_isdigit(*element))
		return (TRUE);
	while (*element && ft_isdigit(*element))
		element++;
	if (*element && *element != ',')
		return (TRUE);
	element++;
	if (*element && !ft_isdigit(*element))
		return (TRUE);
	element++;
	while (*element && ft_isdigit(*element))
		element++;
	if (*element && *element != ',')
		return (TRUE);
	element++;
	if (*element && !ft_isdigit(*element))
		return (TRUE);
	element++;
	while (*element && ft_isdigit(*element))
		element++;
	if (*element && *element != '\n')
		return (TRUE);
	else
		return (FALSE);
}

int	bad_rgb_numbers(char **rgb)
{
	if (ft_strstrlen((const char **)rgb) != 3)
		return (TRUE);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi (rgb[0]) < 0
		|| ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0
		|| ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
		return (TRUE);
	else
		return (FALSE);
}

int	bad_range(float n, float min, float max)
{
	if (n < min || n > max)
		return (TRUE);
	else
		return (FALSE);
}

int	contains_a_light(t_lux *lux)
{
	t_lux	*lux_ptr;

	if (lux == NULL)
		return (FALSE);
	lux_ptr = lux;
	while (lux_ptr)
	{
		if (lux_ptr->type == AMBIENT)
			return (TRUE);
		lux_ptr = lux_ptr->next;
	}
	return (FALSE);
}
