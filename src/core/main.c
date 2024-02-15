/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:18:59 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:43:22 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_data		*dt;
	t_scene		scene;

	printf("Initialising MiniRT.. ");
	dt = malloc(sizeof(t_data));
	if (!dt)
		return (exit_error("failed", dt), -1);
	dt->scene = &scene;
	if (init_data(dt) == FAILURE)
		return (EXIT_FAILURE);
	if (parser(argc, argv, dt) == FAILURE
		|| gui_init(dt) == FAILURE
		|| load_graphics(dt) == FAILURE
		|| nav_setup(dt) == FAILURE)
		return (exit_error("failed", dt), -1);
	printf("done\n");
	launch(dt);
	mlx_loop_hook(dt->mlx, loop, dt);
	mlx_loop(dt->mlx);
	return (EXIT_SUCCESS);
}
