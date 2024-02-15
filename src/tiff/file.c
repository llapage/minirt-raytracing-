/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/21 14:45:50 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tiff.h"

int	tiff_file(int n)
{
	int		fd;
	char	*file;
	char	*suffix;

	file = ft_strdup("./exported_files/minirt_42_render_");
	suffix = ft_itoa(n);
	if (file == NULL || suffix == NULL)
		return (free(file), free(suffix), -1);
	file = ft_strfjoin(file, suffix);
	file = ft_strfjoin(file, ".TIFF");
	if (file == NULL)
		return (free(file), free(suffix), -1);
	fd = open(file, O_CREAT | O_EXCL | O_WRONLY, 0644);
	while (fd == -1 && errno == EEXIST)
		return (free(file), free(suffix), tiff_file(n + 1));
	return (free(file), free(suffix), fd);
}
