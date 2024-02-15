/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:59:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 22:51:10 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/history.h"

static void	*save_state_continued(t_state *st, void *addr, char type);

void	*save_state(void *addr, char type, t_data *dt)
{
	t_state	*st;

	st = push_state(&dt->states);
	if (!(st))
		return (NULL);
	st->addr = addr;
	st->type = type;
	if (type == UINT)
		st->val.ui = *(unsigned int *)addr;
	else if (type == FLOAT)
		st->val.fl = *(float *)addr;
	else if (type == INT)
		st->val.i = *(int *)addr;
	else if (type == VTX)
		st->val.vtx = *(t_vertex *)addr;
	else if (type == VEC)
		st->val.vec = *(t_vector *)addr;
	else if (type == SPHERE)
		st->val.sph = *(t_sphere *)addr;
	else if (type == CYL)
		st->val.cyl = *(t_cyl *)addr;
	else
		return (save_state_continued(st, addr, type));
	return (addr);
}

static void	*save_state_continued(t_state *st, void *addr, char type)
{
	if (type == PLANE)
		st->val.pla = *(t_plane *)addr;
	else if (type == CONE)
		st->val.con = *(t_cone *)addr;
	else if (type == VP)
		st->val.vp = *(t_viewport *)addr;
	else if (type == CAM)
		st->val.cam = *(t_cam *)addr;
	else if (type == AMBIENT)
		st->val.amb = *(t_a_light *)addr;
	else if (type == SPOT)
		st->val.spot = *(t_s_light *)addr;
	else if (type == DIRECTIONAL)
		st->val.dir = *(t_d_light *)addr;
	else if (type == HTS)
	{
		st->val.hts = malloc(S_WIDTH * S_HEIGHT * sizeof(t_hit));
		if (!st->val.hts)
			return (NULL);
		ft_hitcpy(st->val.hts, *(t_hit **)st->addr, S_WIDTH * S_HEIGHT);
	}
	return (addr);
}

t_lux	*save_lux_state(t_lux *lux, t_data *dt)
{
	if (lux->type == AMBIENT)
		save_state(lux->src.amb, lux->type, dt);
	else if (lux->type == SPOT)
		save_state(lux->src.spot, lux->type, dt);
	else if (lux->type == DIRECTIONAL)
		save_state(lux->src.dir, lux->type, dt);
	return (lux);
}

t_obj	*save_obj_state(t_obj *obj, t_data *dt)
{
	if (obj->type == PLANE)
		save_state(obj->shape.plane, obj->type, dt);
	else if (obj->type == SPHERE)
		save_state(obj->shape.sphere, obj->type, dt);
	else if (obj->type == CYL)
		save_state(obj->shape.cyl, obj->type, dt);
	else if (obj->type == CONE)
		save_state(obj->shape.cone, obj->type, dt);
	return (obj);
}
