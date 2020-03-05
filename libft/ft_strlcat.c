/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:25 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/15 17:04:57 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	while (dst[i] && i < size)
		i++;
	k = i;
	while (src[i - k] != '\0' && i + 1 < size)
	{
		dst[i] = src[i - k];
		i++;
	}
	if (k < size)
		dst[i] = '\0';
	return (k + ft_strlen(src));
}
