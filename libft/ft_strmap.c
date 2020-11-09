/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:42:36 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/21 22:00:51 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		len;
	int		i;

	if (s == 0 || f == 0)
		return (NULL);
	len = ft_strlen(s);
	if (len + 1 == 0)
		return (NULL);
	fresh = (char*)malloc(sizeof(*fresh) * (len + 1));
	if (fresh == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(s[i]);
		i += 1;
	}
	fresh[i] = '\0';
	return (fresh);
}
