/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/07 11:11:42 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

t_tiff_params	*tiff_params_continued(t_tiff_params *tp);

t_tiff_params	*tiff_params(uint8_t *image_data, uint16_t width, 
			uint16_t length, t_tiff_params *tp)
{
	tp->image_width = (uint16_t)width;
	tp->image_length = (uint16_t)length;
	tp->image_size = (uint16_t)length * (uint16_t)width;
	tp->image_data = (uint8_t *)image_data;
	tp->bits_per_sample = (uint16_t)8;
	tp->samples_per_pixel = (uint16_t)3;
	tp->rows_per_strip = ft_min((uint16_t)length, (uint16_t)ft_max((uint16_t)1, 
				(uint16_t)8000 / (uint16_t)tp->image_width));
	tp->strip_offsets = (uint16_t)tp->image_length / 
		(uint16_t)tp->rows_per_strip;
	tp->rows_last_strip = (uint16_t)tp->image_length - (
			(uint16_t)tp->strip_offsets * (uint16_t)tp->rows_per_strip);
	if ((uint16_t)tp->rows_last_strip)
		tp->strip_offsets++;
	tp->strip_byte_counts = (uint16_t)tp->strip_offsets;
	tp->strip_byte_value = (uint16_t)tp->rows_per_strip * 
		(uint16_t)tp->image_width * 
		((uint16_t)tp->bits_per_sample / 
			(uint16_t)8) * (uint16_t)tp->samples_per_pixel;
	tp = tiff_params_continued(tp);
	return (tp);
}

t_tiff_params	*tiff_params_continued(t_tiff_params *tp)
{
	tp->strip_byte_value_last_strip = (uint16_t)tp->rows_last_strip * 
		(uint16_t)tp->image_width * 
		((uint16_t)tp->bits_per_sample / 
			(uint16_t)8) * (uint16_t)tp->samples_per_pixel;
	if ((uint16_t)tp->bits_per_sample % (uint16_t)8)
	{
		tp->strip_byte_value = tp->strip_byte_value + 1;
		tp->strip_byte_value_last_strip = tp->strip_byte_value_last_strip + 1;
	}
	tp->strip_offsets_offset = (uint32_t)0xB4;
	tp->strip_byte_counts_offset = (uint32_t)tp->strip_offsets_offset + (
			uint16_t)tp->strip_offsets * (uint32_t)0x4;
	tp->data_offset = (uint32_t)tp->strip_byte_counts_offset + (
			uint16_t)tp->strip_byte_counts * (uint32_t)0x2;
	tp->x_resolution = (uint64_t)(0x64ULL << 32 | 0x2E23);
	tp->y_resolution = (uint64_t)(0x64ULL << 32 | 0x2E23);
	return (tp);
}
