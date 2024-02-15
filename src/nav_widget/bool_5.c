/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:04 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:54:37 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

int	visibility_locked(t_nav *nav)
{
	if (nav && nav->visibility_lock == SET)
		return (TRUE);
	else
		return (FALSE);
}

int	image_locked(t_nav *nav)
{
	if (nav && nav->image_lock == SET)
		return (TRUE);
	else
		return (FALSE);
}

int	is_active(t_nav *nav)
{
	if (nav && nav->active == SET)
		return (TRUE);
	else
		return (FALSE);
}
