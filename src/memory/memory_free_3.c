/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:06:25 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:47:07 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

static void	free_nav_2(t_nav *nav, t_nav *sib)
{
	if (nav && nav->sibling && nav->sibling != sib)
		free_nav_2(nav->sibling, sib);
	if (nav && nav->child)
		free(nav->child);
	free(nav);
}

void	free_nav(t_nav *nav)
{
	if (nav && nav->sibling && nav[NAVOBJECTS].child)
		free_nav_2(nav[NAVOBJECTS].child, nav[NAVOBJECTS].child);
	if (nav && nav->sibling && nav[NAVLIGHTS].child)
		free_nav_2(nav[NAVLIGHTS].child, nav[NAVLIGHTS].child);
	free(nav);
}

void	free_graph(t_graphic *graph)
{
	t_graphic	*gr;

	gr = graph;
	while (gr)
	{
		graph = graph->next;
		free(gr->title);
		free(gr->pixel_int);
		free(gr->pixel_color);
		free(gr);
		gr = graph;
	}
}

void	free_mlx_string(void *mlx_string)
{
	free(((t_mlx_string *)mlx_string)->string);
	free(mlx_string);
}
