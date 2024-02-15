/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:37:57 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:17:24 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

void	set_desc(char *desc, t_nav *nav)
{
	int	i;

	i = 0;
	while (i < 31 && desc[i])
	{
		nav->desc[i] = desc[i];
		i++;
	}
	while (i < 31)
		nav->desc[i++] = '\0';
	nav->desc[i] = '\0';
}

t_nav_directions	nav_dir(int self, int tab, int esc, int ent)
{
	t_nav_directions	nd;

	nd.self = self;
	nd.sibling = tab;
	nd.parent = esc;
	nd.child = ent;
	return (nd);
}

void	set_nav(t_nav *def, int type, char *desc, t_nav_directions nd)
{
	t_nav	*nav;

	nav = &def[nd.self];
	nav->type = type;
	nav->shows = 0; 
	nav->cont.obj = NULL;
	set_desc(desc, nav);
	nav->act = NULL;
	nav->scr = NULL;
	nav->sibling = NULL;
	nav->parent = NULL;
	nav->child = NULL;
	nav->active = SET;
	nav->image_lock = UNSET;
	nav->visibility_lock = UNSET;
	if (nd.sibling != -1)
		nav->sibling = &def[nd.sibling];
	if (nd.parent != -1)
		nav->parent = &def[nd.parent];
	if (nd.child != -1)
		nav->child = &def[nd.child];
}

t_nav_graphics	file_names(char *def, char *fcs, char *sel, char *alt)
{
	t_nav_graphics	ng;

	ng.def = def;
	ng.fcs = fcs;
	ng.sel = sel;
	ng.alt = alt;
	return (ng);
}
