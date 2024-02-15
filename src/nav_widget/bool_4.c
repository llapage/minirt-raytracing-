/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:04 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:54:23 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

int	is_object(t_nav *nav)
{
	if (nav && nav->type == NAVOBJ)
		return (TRUE);
	else
		return (FALSE);
}

int	is_clickable(t_nav *nav)
{
	if (nav && nav->act)
		return (TRUE);
	else
		return (FALSE);
}

int	is_scrollable(t_nav *nav)
{
	if (nav && nav->scr)
		return (TRUE);
	else
		return (FALSE);
}

int	has_child(t_nav *nav)
{
	if (nav && nav->child)
		return (TRUE);
	else
		return (FALSE);
}

int	has_more_siblings(t_nav *sib, t_nav *nav)
{
	if (nav && sib && sib->sibling != nav)
		return (TRUE);
	else
		return (FALSE);
}
