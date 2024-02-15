/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:13:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:38:43 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static void	lock_visibility_siblings(t_nav *nav, t_nav *sib)
{
	lock_visibility_item(nav);
	if (nav->sibling != sib)
		lock_visibility_siblings(nav->sibling, sib);
}

void	lock_visibility_this_generation(t_nav *nav)
{
	lock_visibility_siblings(nav, nav);
}
