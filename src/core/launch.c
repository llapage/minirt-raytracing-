/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:49:25 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 21:05:53 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	launch(t_data *dt)
{
	t_obj	*obj;

	dt->nav_loc = NULL;
	set_visible_this_generation(&dt->nav[NAVRENDER], dt);
	lock_visibility_this_generation(&dt->nav[NAVRENDER]);
	dt->mode = LOADING;
	dt->qlt = LOWRES;
	dt->sub_samples = SUBSAMPLES;
	dt->render_image_pointer = dt->stub_render_image;
	obj = dt->scene->obj;
	while (obj)
	{
		obj->render_image_pointer = obj->stub_render_image;
		obj = obj->next;
	}
	do_render(dt);
	set_render_image_to(&dt->render_image_pointer, dt);
	put_render_image(dt);
	display_main_image(dt);
	default_mode(dt);
	set_render_image_to(&dt->render_image_pointer, dt);
	render(dt);
	unset_current_object(dt);
}
