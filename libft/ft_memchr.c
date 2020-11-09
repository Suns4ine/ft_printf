/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:00:55 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/24 17:12:38 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	res;
	size_t			i;

	str = (unsigned char *)s;
	res = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == res)
			return (&str[i]);
		if (n)
			i++;
	}
	return (NULL);
}
