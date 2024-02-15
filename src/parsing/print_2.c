/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:53:11 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/29 12:28:31 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_cyl(t_obj *obj, int id)
{
	t_cyl	*cyl;

	cyl = obj->shape.cyl;
	printf("OBJECT ID%d\n", id);
	printf("CYLINDER\n");
	print_vertex("ctr vertex", cyl->ctr);
	print_vector("cam-ctr vec", cyl->cam_ctr_vec);
	print_vector("ctr-cam vec", cyl->ctr_cam_vec);
	print_vertex("top ctr", cyl->top.ctr);
	print_vertex("base ctr", cyl->base.ctr);
	print_vector("cam-top vec", cyl->top.cam_ctr_vec);
	print_vector("cam-base vec", cyl->base.cam_ctr_vec);
	print_vector("axis unit", cyl->axis);
	print_vector("top norm", cyl->top.norm);
	print_vector("base norm", cyl->base.norm);
	printf("diameter:\t%0.1f\n", cyl->diameter);
	printf("radius:\t\t%0.1f\n", cyl->radius);
	printf("rim distance:\t%0.1f\n", cyl->rim_dist);
	printf("height:\t\t%0.1f\n", cyl->height);
	printf("shininess:\t%d\n", obj->gloss);
	print_color(obj->color);
}

void	print_cone(t_obj *obj, int id)
{
	t_cone	*cone;

	cone = obj->shape.cone;
	printf("OBJECT ID%d\n", id);
	printf("CONE\n");
	print_vertex("cone apex", cone->ctr);
	print_vector("cam-ctr vec", cone->cam_ctr_vec);
	print_vector("ctr-cam vec", cone->ctr_cam_vec);
	print_vector("axis unit", cone->axis);
	printf("diameter:\t%0.1f\n", cone->diameter);
	printf("height:\t\t%0.1f\n", cone->height);
	printf("radius:\t\t%0.1f\n", cone->radius);
	printf("slant length:\t%0.1f\n", cone->slant_len);
	printf("slant angle:\t%0.5f\n", cone->slant_angle);
	printf("shininess:\t%d\n", obj->gloss);
	print_color(obj->color);
}

void	print_plane(t_obj *obj, int id)
{
	t_plane	*plane;

	plane = obj->shape.plane;
	printf("OBJECT ID%d\n", id);
	printf("PLANE\n");
	print_vertex("plane vertex", plane->ctr);
	print_vector("normal vector", plane->norm);
	print_vector("cam-vtx cevtor", plane->cam_ctr_vec);
	printf("shininess:\t%d\n", obj->gloss);
	print_color(obj->color);
}

void	print_sphere(t_obj *obj, int id)
{
	t_sphere	*sphere;

	sphere = obj->shape.sphere;
	printf("OBJECT ID%d\n", id);
	printf("SPHERE\n");
	print_vertex("ctr vertex", sphere->ctr);
	print_vector("cam-ctr vec", sphere->cam_ctr_vec);
	printf("diameter:\t%0.1f\n", sphere->diameter);
	printf("radius:\t\t%0.1f\n", sphere->radius);
	printf("shininess:\t%d\n", obj->gloss);
	print_color(obj->color);
}

void	print_obj(t_scene *scene)
{
	t_obj	*obj;

	obj = scene->obj;
	while (obj)
	{
		if (obj->type == PLANE)
			print_plane(obj, obj->id);
		if (obj->type == SPHERE)
			print_sphere(obj, obj->id);
		if (obj->type == CYL)
			print_cyl(obj, obj->id);
		if (obj->type == CONE)
			print_cone(obj, obj->id);
		obj = obj->next;
		printf("\n");
	}
}
