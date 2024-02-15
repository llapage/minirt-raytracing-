/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:02:22 by mde-clee          #+#    #+#             */
/*   Updated: 2024/01/22 15:46:52 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static char	*cont_to_str(t_nav *nav, int prec)
{
	if (nav->type == NAVFLT)
		return (ft_ftoa(*nav->cont.float_number, prec));
	else
		return (ft_itoa(*nav->cont.uint_number));
}

static char	*infield_def_str(t_nav *nav)
{
	char	*val;
	char	*tmp;

	val = ft_strdup(nav->desc);
	val = ft_strfjoin(val, " ");
	tmp = cont_to_str(nav, 2);
	if (!tmp)
		return (NULL);
	val = ft_strfjoin(val, tmp);
	free(tmp);
	return (val);
}

static void	push_infield_content(t_nav *nav, t_data *dt)
{
	char	*val;
	t_pixel	pos;
	int		color;

	if (MAC_OS == TRUE)
		pos = pix_l(nav->gp.x + 15, nav->gp.y + 8);
	else
		pos = pix_l(nav->gp.x + 20, nav->gp.y + 25);
	if (is_pressed(nav) == FALSE)
	{
		val = infield_def_str(nav);
		color = GREY;
	}
	else
	{
		val = cont_to_str(nav, 2);
		color = BLACK;
	}
	if (!val)
		exit_error("Error", dt);
	push_screen_string(val, pos, color, dt);
}

static void	push_siblings_content(t_nav *sib, t_nav *nav, t_data *dt)
{
	push_infield_content(sib->child, dt);
	if (sib->sibling != nav)
		push_siblings_content(sib->sibling, nav, dt);
}

void	push_input_dialog_strings(t_data *dt)
{
	push_siblings_content((&dt->nav[INFIELD_1])->parent->child,
		(&dt->nav[INFIELD_1])->parent->child, dt);
}
