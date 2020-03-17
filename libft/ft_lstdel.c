/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:08:06 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/19 12:49:55 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *neode;
	t_list *temp;

	if (*alst != NULL)
	{
		neode = *alst;
		while (neode)
		{
			temp = neode->next;
			(*del)(neode->content, neode->content_size);
			free(neode);
			neode = temp;
		}
		*alst = NULL;
	}
}
