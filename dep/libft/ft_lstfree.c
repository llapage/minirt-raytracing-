/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:32:01 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/25 15:13:48 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*prev_node;

	if (!(lst))
		return ;
	while (*lst)
	{
		prev_node = *lst;
		*lst = (*lst)->next;
		free(prev_node);
	}
}
