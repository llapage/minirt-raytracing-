/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:58:32 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:32:36 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIFF_H
# define TIFF_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>

# define BYTE 0x1
# define SHORT 0x3
# define LONG 0x4
# define RATIONAL 0x5
# define NO_COMPRESSION 0x1
# define RGB 0x2
# define CENTIMETER 0x3
# define TIFF_BIG_ENDIAN 0x4D4D
# define TIFF_LITTLE_ENDIAN 0x4949
# define IMAGE_WIDTH 0x100
# define IMAGE_LENGTH 0x101
# define BITS_PER_SAMPLE 0x102
# define COMPRESSION 0x103
# define PHOTOMETRIC_INTERPRETATION 0x106
# define STRIP_OFFSETS 0x111
# define SAMPLES_PER_PIXEL 0x115
# define ROWS_PER_STRIP 0x116
# define STRIP_BYTE_COUNTS 0x117
# define X_RESOLUTION 0x11A
# define Y_RESOLUTION 0x11B
# define RESOLUTION_UNIT 0x128

typedef struct s_tiff_header
{
	uint16_t	endian;
	uint16_t	version;
	uint32_t	ifd_offset;
}	t_tiff_header;

typedef struct s_tiff_field
{
	uint16_t	tag;
	uint16_t	type;
	uint32_t	count;
	uint32_t	ifd_offset;
}	t_tiff_field;

typedef struct s_tiff_ifd
{
	uint16_t		nb_entries;
	t_tiff_field	*entries;
	uint32_t		ifd_offset;
}	t_tiff_ifd;

typedef struct s_tiff_params
{
	uint8_t		*image_data;
	uint16_t	image_width;
	uint16_t	image_length;
	uint16_t	bits_per_sample;
	uint16_t	strip_offsets;
	uint16_t	samples_per_pixel;
	uint16_t	rows_per_strip;
	uint16_t	rows_last_strip;
	uint16_t	strip_byte_counts;
	uint16_t	strip_byte_value;
	uint16_t	strip_byte_value_last_strip;
	uint32_t	strip_offsets_offset;
	uint32_t	strip_byte_counts_offset;
	uint32_t	data_offset;
	uint32_t	image_size;
	uint64_t	x_resolution;
	uint64_t	y_resolution;
}	t_tiff_params;

t_tiff_header	new_tiff_header(uint16_t endian, 
					uint32_t ifd_offset);
t_tiff_field	new_tiff_field(uint16_t tag, uint16_t type, 
					uint32_t count, uint32_t offset);
t_tiff_params	*tiff_params(uint8_t *image_data, uint16_t width,
					uint16_t length, t_tiff_params *tp);
t_tiff_ifd		new_tiff_ifd(uint16_t nb_entries,
					t_tiff_field *entries, uint32_t ifd_offset);
ssize_t			tiff_out(t_tiff_header th, t_tiff_ifd ti, t_tiff_params tp, 
					int fd);
ssize_t			tiff_export(uint8_t *image_data, uint16_t width,
					uint16_t height);
size_t			bits_per_sample_to_hex(uint16_t a, uint16_t b, 
					uint16_t c, int fd);
size_t			tiff_field_to_hex(t_tiff_field tf, int fd);
size_t			tiff_entries_to_hex(t_tiff_field *tf, uint16_t n, int fd);
ssize_t			uint8_to_hex(uint8_t ui, int fd);
ssize_t			uint16_to_hex(uint16_t ui, int fd);
ssize_t			uint32_to_hex(uint32_t ui, int fd);
ssize_t			uint64_to_hex(uint64_t ui, int fd);
char			*ft_strfjoin(char *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
int				tiff_file(int n);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			tiff_fields(t_tiff_field *tf, t_tiff_params tp);

#endif
