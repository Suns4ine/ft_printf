/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:26:26 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/21 22:40:29 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	node = res;
	while (lst->next)
	{
		lst = lst->next;
		if (!(res->next = f(lst)))
		{
			free(res->next);
		}
		res = res->next;
	}
	return (node);
}
