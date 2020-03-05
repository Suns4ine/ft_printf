/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:09:58 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/19 13:20:12 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin, t_list *new)
{
	t_list *node;

	if (*begin)
	{
		node = *begin;
		while (node->next)
		{
			node = node->next;
		}
		node->next = new;
		node->next = NULL;
	}
	else
		*begin = new;
}
