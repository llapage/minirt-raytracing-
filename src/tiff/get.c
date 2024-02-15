/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:09:24 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/03 14:23:39 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

size_t	tiff_field_to_hex(t_tiff_field tf, int fd)
{
	size_t	addr;

	addr = 0;
	addr += uint16_to_hex((uint16_t)tf.tag, fd);
	addr += uint16_to_hex((uint16_t)tf.type, fd);
	addr += uint32_to_hex((uint32_t)tf.count, fd);
	addr += uint32_to_hex((uint32_t)tf.ifd_offset, fd);
	return ((size_t)addr);
}

size_t	tiff_entries_to_hex(t_tiff_field *tf, uint16_t n, int fd)
{
	int		i;
	size_t	addr;

	i = 0;
	addr = 0;
	while (i < n)
		addr += tiff_field_to_hex(tf[i++], fd);
	return ((size_t)addr);
}

size_t	bits_per_sample_to_hex(uint16_t a, uint16_t b, uint16_t c, int fd)
{
	size_t	addr;

	addr = 0;
	addr += uint16_to_hex((uint16_t)a, fd);
	addr += uint16_to_hex((uint16_t)b, fd);
	addr += uint16_to_hex((uint16_t)c, fd);
	return (addr);
}
