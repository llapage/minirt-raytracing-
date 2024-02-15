/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:08:55 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:30:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

void	set_pos_rt(t_nav *nav, t_nav *parent, int n)
{
	int	i;

	i = -1; 
	while (i++ < n)
	{
		nav[i].tl = pix_l(parent->br.x, parent->tl.y + i * 40);
		nav[i].br = pix_l(nav[i].tl.x + 150, nav[i].tl.y + 40);
		nav[i].gp = nav[i].tl;
	}
}

void	set_next_pos(t_nav *nav, t_nav *obs, int nb)
{
	nav->tl = pix_l(obs->tl.x, obs->br.y + nb * 40);
	nav->br = pix_l(nav->tl.x + 150, nav->tl.y + 40);
	nav->gp = nav->tl;
}

void	set_cam_pos(t_nav *nav)
{
	nav[4].tl = pix_l(nav[3].tl.x, nav[3].br.y);
	nav[4].br = pix_l(nav[4].tl.x + 150, nav[4].tl.y + 40);
	nav[5].tl = pix_l(nav[4].tl.x, nav[4].br.y);
	nav[5].br = pix_l(nav[4].br.x, nav[5].tl.y + 40);
	nav[6].tl = pix_l(nav[4].tl.x, nav[5].br.y);
	nav[6].br = pix_l(nav[4].br.x, nav[6].tl.y + 40);
	nav[4].gp = nav[4].tl;
	nav[5].gp = nav[5].tl;
	nav[6].gp = nav[6].tl;
}

void	set_settings_pos(t_nav *nav)
{
	t_nav	*settings;
	t_nav	*first_element;
	t_nav	*next_element;
	int		nb;

	nb = 0;
	settings = &nav[NAVSETTINGS];
	first_element = settings->child;
	set_next_pos(first_element, settings, nb++);
	next_element = first_element->sibling;
	while (next_element != first_element)
	{
		set_next_pos(next_element, settings, nb++);
		next_element = next_element->sibling;
	}
}
