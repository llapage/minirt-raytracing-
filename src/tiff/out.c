/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:32:21 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

static ssize_t	tiff_out_continued(t_tiff_params tp, int fd, ssize_t addr);

ssize_t	tiff_out(t_tiff_header th, t_tiff_ifd ti, t_tiff_params tp, 
		int fd)
{
	ssize_t		addr;

	addr = 0x0;
	addr += uint16_to_hex(th.endian, fd);
	addr += uint16_to_hex(th.version, fd);
	addr += uint32_to_hex(th.ifd_offset, fd);
	addr += uint16_to_hex(ti.nb_entries, fd);
	addr += tiff_entries_to_hex(ti.entries, ti.nb_entries, fd);
	addr += uint32_to_hex(ti.ifd_offset, fd);
	addr += bits_per_sample_to_hex((uint16_t)tp.bits_per_sample, 
			(uint16_t)tp.bits_per_sample, (uint16_t)tp.bits_per_sample, fd);
	addr += uint64_to_hex((uint64_t)tp.x_resolution, fd);
	addr += uint64_to_hex((uint64_t)tp.y_resolution, fd);
	addr += tiff_out_continued(tp, fd, addr);
	if (addr != tp.data_offset + 3 * tp.image_size)
		return (-1);
	return (addr);
}

static ssize_t	tiff_out_continued(t_tiff_params tp, int fd, ssize_t addr)
{
	uint16_t	strips;
	uint32_t	pixels;

	strips = (uint16_t)0x0;
	while ((uint16_t)strips < (uint16_t)tp.strip_offsets)
		addr += uint32_to_hex((uint32_t)tp.data_offset + (
					(uint16_t)strips++ *(uint16_t)tp.strip_byte_value), fd);
	while ((uint16_t)strips-- > (uint16_t)0x1)
		addr += uint16_to_hex((uint16_t)tp.strip_byte_value, fd);
	if ((uint16_t)tp.strip_byte_value_last_strip)
		addr += uint16_to_hex((uint16_t)tp.strip_byte_value_last_strip, fd);
	else
		addr += uint16_to_hex((uint16_t)tp.strip_byte_value, fd);
	pixels = (uint32_t)0x0;
	while ((uint32_t)pixels < (uint32_t)tp.image_size * 3)
		addr += uint8_to_hex(*(uint8_t *)(tp.image_data + pixels++), fd);
	return (addr);
}
