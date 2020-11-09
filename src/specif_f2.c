/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_f2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:13:09 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:15:27 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		approximator(char *fract, double value)
{
	int apr;
	int i;

	i = ft_strlen(fract);
	value *= 10;
	apr = (int)value;
	apr %= 10;
	if (apr >= 5)
		while (i)
		{
			if (fract[--i] != '9')
			{
				fract[i] += 1;
				return (0);
			}
			else
				fract[i] = '0';
		}
	else
		return (0);
	return (1);
}

char	*ft_ftoa_long(long double value, int width)
{
	int		i;
	size_t	whole;
	char	fract[501];
	int		sign;
	char	ch;

	ch = (width) ? '.' : '\0';
	sign = (value < 0) ? -1 : 1;
	value = value * sign;
	whole = (size_t)value;
	value -= whole;
	width = (width == -1) ? 6 : width;
	i = 0;
	while (width--)
	{
		value *= 10;
		fract[i++] = (size_t)value % 10 + '0';
		value -= (size_t)value;
	}
	fract[i] = '\0';
	whole += approximator(fract, value);
	return (sign < 0) ? ft_strjoin_free("-",\
			ft_strjoin_free(ft_stradd(ft_itoa_un(whole), ch),\
			fract, 1), 2) : ft_strjoin_free(ft_stradd(ft_itoa_un(whole),\
			ch), fract, 1);
}
