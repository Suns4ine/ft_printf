/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:44:24 by madan             #+#    #+#             */
/*   Updated: 2020/10/21 18:21:35 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*ft_stradd(char *str, char ch)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		if (!(new = (char*)ft_strnew(len + 1)))
			return (NULL);
		ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
		new = ft_strnew(1);
	new[len] = ch;
	new[len + 1] = '\0';
	return (new);
}

char	*ft_newstrcat(char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (!(str = (char *)malloc(sizeof(char *) *\
					(ft_strlen(s1) + ft_strlen(s2) - 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while ((s2[len]))
	{
		str[i + len] = s2[len];
		len++;
	}
	str[i + len] = '\0';
	return (str);
}

char	*bigchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*smallchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int		foundchar(char *str, char c)
{
	int i;

	i = 0;
	if (!str || !c)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}
