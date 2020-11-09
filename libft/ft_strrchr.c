/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:22:49 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/13 19:01:54 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		w;
	char	*s1;

	w = ft_strlen(s);
	i = w;
	s1 = (char *)s;
	while (i >= 0)
	{
		if (s1[i] == c)
			return (&s1[i]);
		i--;
	}
	return (NULL);
}
