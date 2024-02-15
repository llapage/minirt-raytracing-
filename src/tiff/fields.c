/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:11:19 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

static void	tiff_fields_continued(t_tiff_field *tf, t_tiff_params tp);

void	tiff_fields(t_tiff_field *tf, t_tiff_params tp)
{
	tf[0] = new_tiff_field((uint16_t)IMAGE_WIDTH,
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)tp.image_width);
	tf[1] = new_tiff_field((uint16_t)IMAGE_LENGTH, 
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)tp.image_length);
	tf[2] = new_tiff_field((uint16_t)BITS_PER_SAMPLE, 
			(uint16_t)SHORT, (uint32_t)3, (uint32_t)0x9E);
	tf[3] = new_tiff_field((uint16_t)COMPRESSION, 
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)NO_COMPRESSION);
	tf[4] = new_tiff_field((uint16_t)PHOTOMETRIC_INTERPRETATION, 
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)RGB);
	tf[5] = new_tiff_field((uint16_t)STRIP_OFFSETS, 
			(uint16_t)LONG, (uint32_t)tp.strip_offsets, 
			(uint32_t)tp.strip_offsets_offset);
	tiff_fields_continued(tf, tp);
}

static void	tiff_fields_continued(t_tiff_field *tf, t_tiff_params tp)
{
	tf[6] = new_tiff_field((uint16_t)SAMPLES_PER_PIXEL, 
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)tp.samples_per_pixel);
	tf[7] = new_tiff_field((uint16_t)ROWS_PER_STRIP,
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)tp.rows_per_strip);
	tf[8] = new_tiff_field((uint16_t)STRIP_BYTE_COUNTS, 
			(uint16_t)SHORT, (uint32_t)tp.strip_byte_counts, 
			(uint32_t)tp.strip_byte_counts_offset);
	tf[9] = new_tiff_field((uint16_t)X_RESOLUTION, 
			(uint16_t)RATIONAL, (uint32_t)1, (uint32_t)0xA4);
	tf[10] = new_tiff_field((uint16_t)Y_RESOLUTION, 
			(uint16_t)RATIONAL, (uint32_t)1, (uint32_t)0xAC);
	tf[11] = new_tiff_field((uint16_t)RESOLUTION_UNIT,
			(uint16_t)SHORT, (uint32_t)1, (uint32_t)CENTIMETER);
}
