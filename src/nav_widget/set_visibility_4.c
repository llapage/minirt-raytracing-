/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visibility_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:51:06 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	reset_siblings(t_nav *sib, t_nav *nav)
{
	if (sib == nav)
		return ;
	try_reset_image(sib);
	reset_siblings(sib->sibling, nav);
}

void	try_reset_image_and_siblings(t_nav *nav)
{
	try_reset_image(nav);
	reset_siblings(nav->sibling, nav);
}

static void	hide_siblings(t_nav *sib, t_nav *nav)
{
	if (sib == nav)
		return ;
	try_hide_item(sib);
	hide_siblings(sib->sibling, nav);
}

void	try_hide_item_and_siblings(t_nav *nav)
{
	try_hide_item(nav);
	hide_siblings(nav->sibling, nav);
}
