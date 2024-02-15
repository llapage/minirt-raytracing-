/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:43:37 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 04:31:49 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdlib.h>
# include "mlx.h"
# include "defs.h"
# include "color.h"
# include "params.h"
# include "../dep/libft/libft.h"

typedef struct s_img
{
	char	*data_addr;
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		size_pixel;
	int		size_image;
	int		endian;
}	t_image;

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_mlx_string
{
	char			*string;
	t_pixel			position;
	unsigned int	color;
}	t_mlx_string;

typedef struct s_screen
{
	int	pixels[S_WIDTH * S_HEIGHT];
}	t_screen;

/* ************************************************************************** */
/*                                                                            */
/*   GET functions                                                            */
/*                                                                            */
/* ************************************************************************** */
char			*pixel_address(t_pixel pixel, t_image *img);
t_pixel			pix_l(int x, int y);
t_mlx_string	*new_mlx_string(char *string, t_pixel position, 
					unsigned int color);

/* ************************************************************************** */
/*                                                                            */
/*   SET functions                                                            */
/*                                                                            */
/* ************************************************************************** */
void			new_image(void *mlx, t_image *img, int width, int height);
void			copy_image(t_image *dest, t_image *src);
void			black_and_white(t_image *img);
void			put_pixel_at(void *address, unsigned int color);
void			set_image_pointer_to_pointer(t_image ***pointer, 
					t_image **image);
void			put_mlx_string(void *mlx_ptr, void *win_ptr, 
					t_mlx_string *mlx_string);
void			my_mlx_pixel_put(t_image *img, int x, int y, 
					unsigned int color);
void			put_mlx_string_list(void *mlx_ptr, void *win_ptr, 
					t_list *mlx_string_list);

/* ************************************************************************** */
/*                                                                            */
/*   BOOL functions                                                           */
/*                                                                            */
/* ************************************************************************** */
int				out_of_bounds(t_pixel pixel);
int				within_area(t_pixel ptr, t_pixel tl, t_pixel br);

#endif
