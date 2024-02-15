/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:24:52 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 18:24:46 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

static t_nav	*do_pane_bottom_element(t_nav *nav)
{
	t_nav	*bottom;
	t_nav	*top;

	bottom = nav;
	top = bottom->sibling;
	while (!(is_drop_down_bottom(bottom)))
	{
		bottom = top;
		top = bottom->sibling;
	}
	return (bottom);
}

t_nav	*pane_bottom_element(t_nav *nav)
{
	if (is_drop_down_bottom(nav))
		return (nav);
	else
		return (do_pane_bottom_element(nav));
}

t_nav	*selected_infield(t_data *dt)
{
	t_nav	*selected;
	t_nav	*infield;

	selected = NULL;
	infield = &dt->nav[INFIELD_1];
	while (selected == NULL && is_infield(infield, dt) == TRUE)
	{
		if (is_pressed(infield) == TRUE)
			selected = infield;
		else
			infield = infield->sibling;
	}
	return (selected);
}

t_nav	*get_top_element(t_nav *nav)
{
	t_nav	*ptr;

	ptr = nav;
	while (is_drop_down_bottom(ptr) == FALSE)
		ptr = ptr->sibling;
	ptr = ptr->sibling;
	return (ptr);
}
