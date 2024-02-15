/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:18:01 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/18 17:09:34 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define SUCCESS 0
# define FAILURE 1
# define CHANGED 1
# define UNCHANGED 0
# define NO_SUBSAMPLES 1
# define TRUE 1
# define FALSE 0
# define SET 1
# define UNSET 0
# define EMPTY 0
# define NONE 0
# define X 0
# define Y 1
# define FLT_MAX		   3.40282347e38F
# define FLT_MIN		   1.1754943508222875e-38F

enum {
	A_LIGHT = 0,
	CAM = 1,
	S_LIGHT = 2,
	SPHERE = 3,
	PLANE = 4,
	CYL = 5,
	D_LIGHT = 6,
	CONE = 7,
	AMBIENT,
	SPOT,
	DIRECTIONAL,
	UINT,
	INT,
	FLOAT,
	VTX,
	VEC,
	HTS,
	VP
};

#endif
