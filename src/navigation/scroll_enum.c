/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_enum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:06:21 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/22 08:53:00 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation.h"

static void	scroll_enum(unsigned int *enum_ptr, int keycode)
{
	int	scroll_direction;

	scroll_direction = get_scroll_direction(keycode);
	*enum_ptr += scroll_direction;
}

void	scroll_and_wrap_enum(unsigned int *enum_ptr, int keycode,
		unsigned int limit)
{
	scroll_enum(enum_ptr, keycode);
	wrap_unsigned(enum_ptr, limit);
}
