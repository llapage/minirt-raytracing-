/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:45:36 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:08:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	put_graphic_named(char *title, t_pixel gp, t_image *img,
		t_data *dt)
{
	t_graphic	*gr;

	gr = get_graphic(dt, title);
	put_graphic(gr, gp, img);
}

void	switch_graphics(t_graphic **a, t_graphic **b)
{
	t_graphic	*tmp;

	tmp = *a; 
	*a = *b; 
	*b = tmp;
}
