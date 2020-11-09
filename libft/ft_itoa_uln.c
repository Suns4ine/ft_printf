/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:38:00 by madan             #+#    #+#             */
/*   Updated: 2020/10/26 17:39:06 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		nill(unsigned long long nb)
{
	long	i;

	i = 2;
	while (nb /= 10)
		i++;
	return (i);
}

char			*ft_itoa_uln(unsigned long long nbr)
{
	long	i;
	char	*str;

	i = nill(nbr);
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
