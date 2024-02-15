/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:47:02 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 09:00:17 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_data.h"

void	set_switch(unsigned int *the_switch)
{
	*the_switch = SET;
}

void	unset_switch(unsigned int *the_switch)
{
	*the_switch = UNSET;
}

void	switch_on_off(unsigned int *the_switch)
{
	if (is_set(*the_switch))
		unset_switch(the_switch);
	else
		set_switch(the_switch);
}

void	grab_scene(t_data *dt)
{
	dt->scene_grab = SET;
}

void	release_scene(t_data *dt)
{
	dt->scene_grab = UNSET;
}
