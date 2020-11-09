/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:45:34 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/24 17:10:33 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnlen(const char *str, int maxlen)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	if (i > maxlen)
		return (maxlen);
	return (i);
}
