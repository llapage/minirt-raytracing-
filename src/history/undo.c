/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 02:13:05 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

static void	undo_state_continued(t_state *st);

t_state	*undo_state(t_data *dt)
{
	t_state	*st;

	st = pop_state(&dt->states);
	if (st->type == UINT)
		*(unsigned int *)st->addr = st->val.ui;
	else if (st->type == FLOAT)
		*(float *)st->addr = st->val.fl;
	else if (st->type == INT)
		*(int *)st->addr = st->val.i;
	else if (st->type == VTX)
		*(t_vertex *)st->addr = st->val.vtx;
	else if (st->type == VEC)
		*(t_vector *)st->addr = st->val.vec;
	else if (st->type == CYL)
		*(t_cyl *)st->addr = st->val.cyl;
	else if (st->type == PLANE)
		*(t_plane *)st->addr = st->val.pla;
	else if (st->type == SPHERE)
		*(t_sphere *)st->addr = st->val.sph;
	else if (st->type == CONE)
		*(t_cone *)st->addr = st->val.con;
	else
		undo_state_continued(st);
	free(st);
	return (dt->states);
}

static void	undo_state_continued(t_state *st)
{
	if (st->type == VP)
		*(t_viewport *)st->addr = st->val.vp;
	else if (st->type == CAM)
		*(t_cam *)st->addr = st->val.cam;
	else if (st->type == AMBIENT)
		*(t_a_light *)st->addr = st->val.amb;
	else if (st->type == SPOT)
		*(t_s_light *)st->addr = st->val.spot;
	else if (st->type == DIRECTIONAL)
		*(t_d_light *)st->addr = st->val.dir;
	else if (st->type == HTS)
	{
		ft_hitcpy(*(t_hit **)st->addr, st->val.hts, S_WIDTH * S_HEIGHT);
		free(st->val.hts);
	}
}
