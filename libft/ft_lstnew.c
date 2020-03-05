/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:32:06 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/16 14:17:07 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(*node));
	if (node == 0)
		return (NULL);
	if (content == 0)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = malloc(content_size);
		if (node->content == 0)
		{
			free(node);
			return (NULL);
		}
		ft_node_fill((node->content), content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
