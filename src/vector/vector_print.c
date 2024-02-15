/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:44:35 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/02 14:24:09 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

void	print_vertex(char *desc, t_vertex vtx)
{
	printf("%s:\t%0.12fx, %0.12fy, %0.12fz\n", desc, vtx.x, vtx.y, vtx.z);
}

void	print_vector(char *desc, t_vector vec)
{
	printf("%s:\t%0.12fx, %0.12fy, %0.12fz\n", desc, vec.x, vec.y, vec.z);
}
