/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:36:17 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/16 15:53:10 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needl, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		ret;
	char		*str1;

	i = 0;
	str1 = (char *)str;
	if (*needl == '\0')
		return (str1 + i);
	ret = ft_strlen(needl);
	while (*(str1 + i) && i < len)
	{
		j = 0;
		while (needl[j] && str[i + j] == needl[j] && i + j < len)
		{
			j++;
			if (!needl[j])
				return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
