/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:57:14 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/26 17:29:49 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(long nb)
{
	int	i;

	i = 2;
	while (nb /= 10)
		i++;
	return (i);
}

char	*ft_itoa_ul(long nbr)
{
	int		i;
	char	*str;
	int		sign;

	i = len(nbr);
	sign = 0;
	if (nbr == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	if (nbr < 0)
	{
		nbr *= (-1);
		sign = 1;
	}
	i += sign;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
