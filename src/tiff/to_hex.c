/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:07:38 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/27 03:26:38 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

ssize_t	uint8_to_hex(uint8_t ui, int fd)
{
	if (write(fd, &ui, 1) != 1)
		return (-1);
	return ((size_t)1);
}

ssize_t	uint16_to_hex(uint16_t ui, int fd)
{
	int		i;
	uint8_t	hex;

	i = 0;
	while (i < 2)
	{
		hex = (ui >> (i++ *8)) & 0xFF;
		if (write(fd, &hex, 1) != 1)
			return (-1);
	}
	return ((size_t)2);
}

ssize_t	uint32_to_hex(uint32_t ui, int fd)
{
	int		i;
	uint8_t	hex;

	i = 0;
	while (i < 4)
	{
		hex = (ui >> (i++ *8)) & 0xFF;
		if (write(fd, &hex, 1) != 1)
			return (-1);
	}
	return ((size_t)4);
}

ssize_t	uint64_to_hex(uint64_t ui, int fd)
{
	int		i;
	uint8_t	hex;

	i = 0;
	while (i < 8)
	{
		hex = (ui >> (i++ *8)) & 0xFF;
		if (write(fd, &hex, 1) != 1)
			return (-1);
	}
	return ((size_t)8);
}
