/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:50:15 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/26 07:31:16 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	put_siblings_color_labels(t_nav *sib, t_nav *nav, t_image *img)
{
	if (sib == nav)
		return ;
	if (is_visible(sib))
		put_color_label(sib, img);
	put_siblings_color_labels(sib->sibling, nav, img);
}

static void	do_put_color_labels(t_nav *nav, t_image *img)
{
	if (is_visible(nav))
		put_color_label(nav, img);
	put_siblings_color_labels(nav->sibling, nav, img);
}

void	put_color_labels(t_data *dt, t_image *img)
{
	t_nav	*objects;

	objects = &dt->nav[NAVOBJECTS];
	do_put_color_labels(objects->child, img);
}
