/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:45:27 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/12 13:50:24 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_node_fill(void *next, const void *prev, size_t content_size)
{
	unsigned int	i;
	unsigned char	*n1;
	unsigned char	*p1;

	i = 0;
	n1 = (unsigned char *)next;
	p1 = (unsigned char *)prev;
	if (content_size == 0 || n1 == p1)
		return (next);
	while (i < content_size)
	{
		n1[i] = p1[i];
		i++;
	}
	return (next);
}
