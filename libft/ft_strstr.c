/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:54:24 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/21 20:22:53 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needl)
{
	int		i;
	int		r;

	i = 0;
	if (*needl == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		r = 0;
		if (str[i] == needl[r])
		{
			while (needl[r] == str[i + r] || needl[r] == '\0')
			{
				if (needl[r] == '\0')
					return ((char *)str + i);
				r++;
			}
		}
		i++;
	}
	return (NULL);
}
