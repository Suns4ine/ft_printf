/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:45:10 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/28 18:09:30 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	if (!(str = malloc(size + 1)))
	{
		ft_strdel(&str);
		return (NULL);
	}
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
