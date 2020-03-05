/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:33:40 by cshawnee          #+#    #+#             */
/*   Updated: 2020/03/02 16:11:48 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nil(size_t nb)
{
	int i;

	i = 0;
	while(nb / 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa_un(size_t nbr)
{
	int		i;
	char	*str;

	i = nil(nbr);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}