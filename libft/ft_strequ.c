/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:28:35 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/13 18:19:26 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	if (!s1 || !s2)
		return (1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	else
		return (0);
}
