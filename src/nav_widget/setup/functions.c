/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:17:14 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 09:48:30 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

void	set_act(t_nav *nav, int n, void (*f)(t_nav *, t_data *))
{
	int	i;

	i = 0;
	while (i < n)
		nav[i++].act = f;
}
