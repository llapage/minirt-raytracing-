/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:11:53 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/03 14:24:49 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

t_tiff_header	new_tiff_header(uint16_t endian, uint32_t ifd_offset)
{
	t_tiff_header	th;

	th.endian = (uint16_t)endian;
	th.version = (uint16_t) '*';
	th.ifd_offset = (uint32_t)ifd_offset;
	return (th);
}

t_tiff_ifd	new_tiff_ifd(uint16_t nb_entries, t_tiff_field *entries,
		uint32_t ifd_offset)
{
	t_tiff_ifd	ti;

	ti.nb_entries = nb_entries;
	ti.entries = entries;
	ti.ifd_offset = ifd_offset;
	return (ti);
}

t_tiff_field	new_tiff_field(uint16_t tag, uint16_t type, uint32_t count,
		uint32_t offset)
{
	t_tiff_field	tf;

	tf.tag = tag;
	tf.type = type;
	tf.count = count;
	tf.ifd_offset = offset;
	return (tf);
}
