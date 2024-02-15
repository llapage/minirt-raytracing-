/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_pane_move_item.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 15:10:48 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	move_item_up(t_nav *nav)
{
	nav->gp.y -= 40;
	nav->tl.y -= 40;
	nav->br.y -= 40;
}

void	move_item_down(t_nav *nav)
{
	nav->gp.y += 40;
	nav->tl.y += 40;
	nav->br.y += 40;
}

void	move_item_top(t_nav *nav)
{
	nav->gp.y = 40;
	nav->tl.y = 40;
	nav->br.y = 80;
}

void	move_item_bottom(t_nav *nav, t_nav *bottom)
{
	nav->tl.y = bottom->tl.y;
	nav->br.y = bottom->br.y;
	nav->gp.y = bottom->gp.y;
}
