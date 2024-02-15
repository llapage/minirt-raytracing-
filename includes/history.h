/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:25:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/28 20:31:10 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "viewport.h"
# include "vector.h"
# include "scene.h"
# include "defs.h"
# include "gui.h"

typedef union s_var
{
	unsigned int	ui; 
	t_viewport		vp;
	t_vector		vec;
	t_vertex		vtx;
	t_sphere		sph;
	t_plane			pla;
	t_cone			con;
	t_s_light		spot;
	t_a_light		amb;
	t_d_light		dir;
	t_hit			*hts;
	t_cyl			cyl;
	t_cam			cam;
	float			fl; 
	int				i;
}	t_var;

typedef struct s_state
{
	struct s_state	*next;
	t_var			val;
	void			*addr;
	char			type;
}	t_state;

t_state	*push_state(t_state **top);
t_state	*pop_state(t_state **top);
t_state	*undo_state(t_data *dt);
t_obj	*save_obj_state(t_obj *obj, t_data *dt);
void	*save_state(void *addr, char type, t_data *dt);
void	restore_state(t_data *dt);
void	revert_to_restore_point(t_data *dt);

/* ************************************************************************** */
/*                                                                            */
/*   SET Utilities                                                            */
/*                                                                            */
/* ************************************************************************** */
void	clear_restore_point(t_data *dt);
void	revert_to_and_clear_restore_point(t_data *dt);
void	set_restore_point(t_data *dt);
void	*ft_hitcpy(t_hit *dst, t_hit *src, size_t n);
void	clear_all_states(t_state **states);

/* ************************************************************************** */
/*                                                                            */
/*   BOOL Utilities                                                           */
/*                                                                            */
/* ************************************************************************** */
int		no_changes_were_made(t_data *dt);
int		at_restore_point(t_data *dt);

#endif
