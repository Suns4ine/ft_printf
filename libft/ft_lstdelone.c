/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:00:20 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/19 12:54:36 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *neode;

	if (*alst != NULL)
	{
		neode = *alst;
		del((neode)->content, ((neode)->content_size));
		free(neode);
		*alst = NULL;
	}
}
