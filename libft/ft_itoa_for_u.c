/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_for_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:33:18 by madan             #+#    #+#             */
/*   Updated: 2020/10/26 17:34:51 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(unsigned long nb)
{
	int i;

	i = 2;
	while (nb /= 10)
		i++;
	return (i);
}

char		*ft_itoa_for_u(unsigned long nbr)
{
	int		i;
	char	*str;

	i = len(nbr);
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
