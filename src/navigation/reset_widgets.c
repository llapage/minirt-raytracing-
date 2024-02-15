/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_widgets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/26 10:09:16 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static int	hide_and_reset(t_nav *nav, t_nav *sib);
static int	do_hide_and_reset(t_nav *nav);

int	reset_widgets(t_data *dt)
{
	int	changes;

	changes = hide_and_reset(&dt->nav[NAVRENDER], &dt->nav[NAVRENDER]);
	return (changes);
}

static int	hide_and_reset(t_nav *nav, t_nav *sib)
{
	int	changes;

	changes = 0;
	changes += do_hide_and_reset(nav);
	if (has_child(nav))
		changes += hide_and_reset(nav->child, nav->child);
	if (has_more_siblings(nav, sib))
		changes += hide_and_reset(nav->sibling, sib);
	return (changes);
}

static int	do_hide_and_reset(t_nav *nav)
{
	int	changes;

	changes = 0;
	changes += try_hide_item(nav);
	changes += try_reset_image(nav);
	return (changes);
}
