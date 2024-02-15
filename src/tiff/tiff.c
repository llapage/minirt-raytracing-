/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:36:03 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

static ssize_t	output_to_file(t_tiff_header th, t_tiff_ifd ti, 
					t_tiff_params tp);

ssize_t	tiff_export(uint8_t *image_data, uint16_t width, uint16_t height)
{
	t_tiff_header	th;
	t_tiff_ifd		ti;
	t_tiff_field	tf[0xC];
	t_tiff_params	tp;
	ssize_t			final_offset;

	th = new_tiff_header((uint16_t)TIFF_LITTLE_ENDIAN, (uint16_t)0x8);
	ti = new_tiff_ifd((uint16_t)0xC, tf, (uint32_t)0x0);
	tiff_params(image_data, width, height, &tp);
	tiff_fields(tf, tp);
	final_offset = output_to_file(th, ti, tp);
	return (final_offset);
}

static ssize_t	output_to_file(t_tiff_header th, t_tiff_ifd ti, 
			t_tiff_params tp)
{
	int		fd;
	ssize_t	final_offset;

	fd = tiff_file(1);
	if (fd == -1)
		return (-1);
	final_offset = tiff_out(th, ti, tp, fd);
	close(fd);
	return (final_offset);
}
