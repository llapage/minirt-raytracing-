/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:16:36 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 00:20:29 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	revert_mode(t_data *dt)
{
	if (was_default_mode(dt))
		default_mode(dt);
	else if (was_edit_mode(dt))
		edit_mode(dt);
	else
		default_mode(dt);
}

void	set_new_mode(int mode, t_data *dt)
{
	dt->mode_prev = dt->mode;
	dt->mode = mode;
}

void	default_mode(t_data *dt)
{
	if (dt->mode == DEFAULT)
		return ;
	set_new_mode(DEFAULT, dt);
	dt->qlt = STD;
	dt->sub_samples = NO_SUBSAMPLES;
	point_to_full_render_images(dt);
}

void	edit_mode(t_data *dt)
{
	if (dt->mode == EDIT)
		return ;
	set_new_mode(EDIT, dt);
	dt->qlt = LOWRES;
	dt->sub_samples = SUBSAMPLES;
	point_to_stub_render_images(dt);
}

void	input_mode(t_data *dt)
{
	if (dt->qlt == LOWRES)
		return ;
	dt->qlt = LOWRES;
	dt->sub_samples = SUBSAMPLES;
	point_to_stub_render_images(dt);
}
