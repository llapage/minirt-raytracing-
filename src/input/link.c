/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:26:31 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 23:52:19 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	adopt_input_dialog_buttons(t_nav *nav, t_data *dt)
{
	dt->nav[NAVCANCEL].parent = nav;
	dt->nav[NAVCONFIRM].parent = nav;
}

static void	do_link(t_nav *infield, t_nav *nav)
{
	infield->cont = nav->cont;
	infield->type = nav->type;
	infield->parent = nav->parent;
	ft_memcpy(infield->desc, nav->desc, 32);
}

static void	link_siblings(t_nav *infield, t_nav *sib, t_nav *nav)
{
	if (sib == nav)
		return ;
	do_link(infield, sib);
	link_siblings(infield->sibling, sib->sibling, nav);
}

static void	link_infields(t_nav *nav, t_data *dt)
{
	t_nav	*infield;

	infield = &dt->nav[INFIELD_1];
	do_link(infield, nav);
	link_siblings(infield->sibling, nav->sibling, nav);
}

void	input_dialog_link_item(t_nav *nav, t_data *dt)
{
	adopt_input_dialog_buttons(nav, dt);
	link_infields(nav->child, dt);
}
