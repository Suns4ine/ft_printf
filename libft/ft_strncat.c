/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:59:29 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/21 19:45:27 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int ter;

	i = 0;
	ter = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[ter + i] = s2[i];
		i++;
	}
	s1[ter + i] = '\0';
	return (s1);
}
