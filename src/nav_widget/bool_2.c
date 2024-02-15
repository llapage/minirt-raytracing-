/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:24:04 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:52:04 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

int	is_drop_down_parent(t_nav *nav)
{
	if (nav && (nav->type == NAVOBJECTS
			|| nav->type == NAVLIGHTS
			|| nav->type == NAVCAM
			|| nav->type == NAVSETTINGS
			|| nav->type == NAVOBJ
			|| nav->type == NAVLUX))
		return (TRUE);
	else
		return (FALSE);
}

int	drop_down_limit_reached(t_nav *nav, t_data *dt)
{
	if ((nav->parent == &dt->nav[NAVOBJECTS] 
			|| nav->parent == &dt->nav[NAVLIGHTS]
			|| nav->parent == &dt->nav[NAVCAM])
		&& nav->tl.y > 160)
		return (TRUE);
	else
		return (FALSE);
}

int	within_drop_down_limit(t_nav *nav)
{
	if (nav->tl.y < 161)
		return (TRUE);
	else
		return (FALSE);
}

int	is_drop_down_bottom(t_nav *nav)
{
	if (nav->sibling->gp.y <= nav->gp.y)
		return (TRUE);
	else
		return (FALSE);
}
