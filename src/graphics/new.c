/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:08 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:59:26 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static int	allocate_memory(t_graphic **gr, char *file, int width, int height);
static void	set_parameters(t_graphic *gr, int width, int height);
static void	push_graphic(t_graphic **top, t_graphic *gr);

int	new_graphic(t_graphic **top, char *file, int width, int height)
{
	t_graphic	*gr;

	if (allocate_memory(&gr, file, width, height) == FAILURE)
		return (FAILURE);
	set_parameters(gr, width, height);
	push_graphic(top, gr);
	if (parse_file(gr) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	allocate_memory(t_graphic **gr, char *file, int width, int height)
{
	char			*ttle;
	t_color			*pixel_color;
	unsigned int	*pixel_int;

	(void)file;
	*gr = malloc(sizeof(t_graphic));
	ttle = ft_strdup(file);
	pixel_color = malloc(width * height * sizeof(t_color));
	pixel_int = malloc(width * height * sizeof(unsigned int));
	if (!ttle || !*gr || !pixel_color || !pixel_int)
	{
		free(*gr);
		free(ttle);
		free(pixel_color);
		return (FAILURE);
	}
	(*gr)->title = ttle;
	(*gr)->pixel_color = pixel_color;
	(*gr)->pixel_int = pixel_int;
	return (SUCCESS);
}

static void	set_parameters(t_graphic *gr, int width, int height)
{
	gr->width = width;
	gr->height = height;
	gr->size = width * height;
}

static void	push_graphic(t_graphic **top, t_graphic *gr)
{
	gr->next = *top;
	*top = gr;
}
