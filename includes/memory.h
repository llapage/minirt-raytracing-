/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:07:20 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:56:22 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>
# include <mlx.h>
# include "../dep/libft/libft.h"
# include "navigation.h"
# include "history.h"
# include "t_data.h"
# include "vector.h"
# include "scene.h"
# include "defs.h"

typedef struct s_data	t_data;
typedef struct s_nav	t_nav;

void	exit_error(char *s, t_data *dt);
void	free_data(t_data *data);
int		malloc_error(t_data *dt);
int		init_data(t_data *data);
void	free_mlx_string(void *mlx_string);
void	free_lux(t_scene *scene);
void	free_obj(t_data *dt);
void	free_nav(t_nav *nav);
void	free_graph(t_graphic *graph);
void	nav_init(t_data *dt);

#endif
