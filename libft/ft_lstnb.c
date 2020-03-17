/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:05:58 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/19 13:17:01 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnb(t_list *begin, unsigned int nbr)
{
	unsigned int	i;
	t_list			*new;

	i = 0;
	if (begin != NULL)
	{
		new = begin;
		while (i < nbr)
		{
			new = new->next;
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
