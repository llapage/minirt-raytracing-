/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_reflections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:10:05 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/31 22:18:57 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

void	switch_reflections(t_nav *nav, t_data *dt)
{
	switch_graphics(&nav->default_graphic, &nav->select_graphic);
	switch_graphics(&nav->focus_graphic, &nav->alternative_graphic);
	switch_on_off(&dt->reflections_switch);
	edit_mode(dt);
	set_visible_this_generation_and_up(nav, dt);
}
