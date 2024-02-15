/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 22:55:18 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

void	clear_restore_point(t_data *dt)
{
	if (at_restore_point(dt) == TRUE)
	{
		undo_state(dt);
		dt->restore_point = NULL;
	}
}

void	revert_to_and_clear_restore_point(t_data *dt)
{
	revert_to_restore_point(dt);
	clear_restore_point(dt);
}

void	set_restore_point(t_data *dt)
{
	dt->restore_point = dt->states;
}

void	*ft_hitcpy(t_hit *dest, t_hit *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL
		&& src == NULL)
		return (NULL);
	while (i < n)
		*(dest + i++) = *src++;
	return (dest);
}

void	clear_all_states(t_state **states)
{
	t_state	*st;

	st = *states;
	while (st)
	{
		*states = (*states)->next;
		if (st->type == HTS)
			free(st->val.hts);
		free(st);
		st = *states;
	}
	*states = NULL;
}
