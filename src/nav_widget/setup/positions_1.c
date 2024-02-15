/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:08:55 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:30:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/nav_widget_setup.h"

static void	set_pos_2(t_nav *nav, int ms, int mh)
{
	nav[NAVSETTINGS].br = pix_l(ms + 255, 40);
	nav[NAVEXIT].br = pix_l(ms + 340, 40);
	nav[INFIELD_1].br = pix_l(ms + 75, mh);
	nav[INFIELD_2].br = pix_l(ms + 75, mh + 40);
	nav[INFIELD_3].br = pix_l(ms + 75, mh + 80);
	nav[NAVCANCEL].br = pix_l(ms - 45, mh - 41);
	nav[NAVCONFIRM].br = pix_l(ms + 65, mh - 41);
	nav[NAVRENDER].gp = pix_l(ms - 315, 7); 
	nav[NAVRETURN].gp = pix_l(ms - 230, 7); 
	nav[NAVEXPORT].gp = pix_l(ms - 145, 7); 
	nav[NAVOBJECTS].gp = pix_l(ms - 60, 7); 
	nav[NAVLIGHTS].gp = pix_l(ms + 25, 7); 
	nav[NAVCAM].gp = pix_l(ms + 110, 7); 
	nav[NAVSETTINGS].gp = pix_l(ms + 195, 7); 
	nav[NAVEXIT].gp = pix_l(ms + 280, 7); 
	nav[INFIELD_1].gp = pix_l(ms - 75, mh - 40);
	nav[INFIELD_2].gp = pix_l(ms - 75, mh);
	nav[INFIELD_3].gp = pix_l(ms - 75, mh + 40);
	nav[NAVCANCEL].gp = pix_l(ms - 75, mh - 66);
	nav[NAVCONFIRM].gp = pix_l(ms + 40, mh - 66);
}

void	set_pos(t_nav *nav)
{
	int	ms; 
	int	mh; 

	ms = S_WIDTH / 2;
	mh = S_HEIGHT / 2;
	nav[NAVRENDER].tl = pix_l(ms - 340, 0); 
	nav[NAVRETURN].tl = pix_l(ms - 255, 0); 
	nav[NAVEXPORT].tl = pix_l(ms - 170, 0); 
	nav[NAVOBJECTS].tl = pix_l(ms - 85, 0); 
	nav[NAVLIGHTS].tl = pix_l(ms, 0); 
	nav[NAVCAM].tl = pix_l(ms + 85, 0); 
	nav[NAVSETTINGS].tl = pix_l(ms + 170, 0); 
	nav[NAVEXIT].tl = pix_l(ms + 255, 0); 
	nav[INFIELD_1].tl = pix_l(ms - 75, mh - 40);
	nav[INFIELD_2].tl = pix_l(ms - 75, mh);
	nav[INFIELD_3].tl = pix_l(ms - 75, mh + 40);
	nav[NAVCANCEL].tl = pix_l(ms - 75, mh - 66);
	nav[NAVCONFIRM].tl = pix_l(ms + 40, mh - 66);
	nav[NAVRENDER].br = pix_l(ms - 255, 40);
	nav[NAVRETURN].br = pix_l(ms - 170, 40);
	nav[NAVEXPORT].br = pix_l(ms - 85, 40);
	nav[NAVOBJECTS].br = pix_l(ms, 40);
	nav[NAVLIGHTS].br = pix_l(ms + 85, 40);
	nav[NAVCAM].br = pix_l(ms + 170, 40);
	set_pos_2(nav, ms, mh);
}
