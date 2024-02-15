/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:44:47 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 21:50:11 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

int	is_set(unsigned int the_switch)
{
	if (the_switch == SET)
		return (TRUE);
	else
		return (FALSE);
}
