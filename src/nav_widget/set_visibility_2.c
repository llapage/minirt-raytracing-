/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visibility_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 00:49:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nav_widget.h"

void	set_visible_this_generation(t_nav *nav, t_data *dt)
{
	set_visible_item(nav);
	set_visible_siblings(nav->sibling, nav, dt);
}

void	set_visible_this_generation_and_up(t_nav *nav, t_data *dt)
{
	if (nav == &dt->nav[NAVDEF])
		return ;
	set_visible_this_generation(nav, dt); 
	set_visible_this_generation_and_up(nav->parent, dt);
}

void	put_if_visible_this_generation_and_down(t_nav *nav, t_nav *sib,
		t_image *img, t_data *dt)
{
	if (nav->shows)
		put_graphic(*nav->current_graphic, nav->gp, img);
	if (nav->sibling != sib)
		put_if_visible_this_generation_and_down(nav->sibling, sib, img, dt);
	if (nav->child)
		put_if_visible_this_generation_and_down(nav->child, 
			nav->child, img, dt);
}

void	put_if_visible_all(t_data *dt, t_image *img)
{
	put_if_visible_this_generation_and_down(&dt->nav[NAVRENDER], 
		&dt->nav[NAVRENDER], img, dt);
}
