/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_under_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:35:39 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:45:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static t_nav	*do_nav_under_pointer(t_pixel ptr, t_nav *nav, t_nav *sib);
static t_nav	*search_children_and_siblings(t_pixel ptr, t_nav *nav,
					t_nav *sib);
static int		found_match(t_pixel ptr, t_nav *nav);

t_nav	*nav_under_pointer(t_pixel ptr, t_data *dt)
{
	return (do_nav_under_pointer(ptr, &dt->nav[NAVRENDER], 
			&dt->nav[NAVRENDER]));
}

static t_nav	*do_nav_under_pointer(t_pixel ptr, t_nav *nav, t_nav *sib)
{
	if (found_match(ptr, nav) == TRUE)
		return (nav);
	else
		return (search_children_and_siblings(ptr, nav, sib));
}

static t_nav	*search_children_and_siblings(t_pixel ptr, t_nav *nav,
			t_nav *sib)
{
	t_nav	*match;

	match = NULL;
	if (has_child(nav))
		match = do_nav_under_pointer(ptr, nav->child, nav->child);
	if (!match && has_more_siblings(nav, sib))
		match = do_nav_under_pointer(ptr, nav->sibling, sib);
	return (match);
}

static int	found_match(t_pixel ptr, t_nav *nav)
{
	if (nav->shows && within_area(ptr, nav->tl, nav->br))
		return (TRUE);
	return (FALSE);
}
