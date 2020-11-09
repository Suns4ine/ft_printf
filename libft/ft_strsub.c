/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:49:52 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/16 14:44:18 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	char			*res;

	i = 0;
	str = (char *)s;
	if (s == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (NULL);
	while (i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
