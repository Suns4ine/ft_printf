/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:33:40 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/26 17:35:47 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nil(long long nb)
{
	int i;

	i = 2;
	while (nb /= 10)
		i++;
	return (i);
}

char	*ft_itoa_un(long long nbr)
{
	int		i;
	char	*str;

	if (nbr == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
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
