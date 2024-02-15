/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_item_adjacent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/23 15:11:08 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	align_item(t_nav *nav, t_nav *src, int item_nb)
{
	nav->tl = pix_l(src->br.x, src->tl.y + item_nb * 40);
	nav->br = pix_l(nav->tl.x + 150, nav->tl.y + 40);
	nav->gp = nav->tl;
}

static void	align_siblings(t_nav *sib, t_nav *nav, t_nav *src, int item_nb)
{
	if (sib == nav)
		return ;
	align_item(sib, src, item_nb);
	align_siblings(sib->sibling, nav, src, item_nb + 1);
}

void	move_item_adjacent(t_nav *nav, t_nav *src)
{
	align_item(nav, src, 0);
	align_siblings(nav->sibling, nav, src, 1);
}
