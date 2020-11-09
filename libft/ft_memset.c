/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:23:24 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/09 15:45:27 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	buf = (unsigned char *)b;
	while (len > i)
	{
		buf[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
