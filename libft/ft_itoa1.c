/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:45:35 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/26 17:26:58 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_neg(int *n, int *sign)
{
	if (*n < 0)
	{
		*n *= (-1);
		*sign = 1;
	}
	else
		return ;
}

char			*ft_itoa(int n)
{
	int		i;
	int		temp;
	int		sign;
	char	*y;

	i = 2;
	temp = n;
	sign = 0;
	ft_neg(&n, &sign);
	if (n == -2147483648)
		return ("-2147483648");
	while (temp /= 10)
		i++;
	i = i + sign;
	if (!(y = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	y[--i] = '\0';
	while (i--)
	{
		y[i] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		y[0] = '-';
	return (y);
}
