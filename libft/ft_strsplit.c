/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:12:29 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/17 13:38:25 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return (NULL);
}

static int	ft_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		j++;
	return (j);
}

static char	*ft_wordfill(char const *s, char c, int *i)
{
	int		r;
	char	*str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s)));
	if (str == 0)
		return (NULL);
	r = 0;
	while (s[*i] != c && s[*i])
	{
		str[r] = s[*i];
		r += 1;
		*i += 1;
	}
	str[r] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = ft_words(s, c);
	k = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(*res) * (j + 2));
	if (res == 0)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (k < j && s[i])
	{
		res[k] = ft_wordfill(s, c, &i);
		if (res[k] == NULL)
			return (ft_free(res));
		k++;
	}
	res[k] = NULL;
	return (res);
}
