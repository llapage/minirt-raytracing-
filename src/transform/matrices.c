/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:48 by llapage           #+#    #+#             */
/*   Updated: 2023/12/22 09:32:30 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vector	multiply_matrix(t_vector src_v, float m[3][3])
{
	t_vector	dest_v;

	dest_v.x = src_v.x * m[0][0] + src_v.y * m[0][1] + src_v.z * m[0][2];
	dest_v.y = src_v.x * m[1][0] + src_v.y * m[1][1] + src_v.z * m[1][2];
	dest_v.z = src_v.x * m[2][0] + src_v.y * m[2][1] + src_v.z * m[2][2];
	return (dest_v);
}
