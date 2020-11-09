/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specid_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:10:24 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 18:46:12 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*else_p(t_print *data, char *final, char *str)
{
	while (data->tag->diff != 0)
	{
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	final[data->tag->i++] = '0';
	final[data->tag->i++] = 'x';
	data->tag->count = data->tag->i + data->tag->count;
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count + 2)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

char	*minus_p(t_print *data, char *final, char *str)
{
	final = ft_newstrcat("0x", final);
	data->tag->i = 2;
	data->tag->count = data->tag->count + 2;
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	while (data->tag->diff != 0)
	{
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	final[data->tag->i] = '\0';
	return (final);
}

char	*tagmakerp(t_print *data, char *str)
{
	char	*final;

	data->tag->count = ft_strlen(str);
	data->tag->withstr = ft_strlen(str);
	data->tag->count = (data->width >= data->tag->count)\
						? data->width : data->tag->count;
	data->tag->diff = (data->len >= (data->tag->count +\
						2)) ? data->len - (data->tag->count + 2) : 0;
	if (!(final = (char *)malloc(sizeof(char )\
						* (data->tag->diff + data->tag->count + 3))))
		return (NULL);
	if (data->flag->minus)
		final = minus_p(data, final, str);
	else
		final = else_p(data, final, str);
	free(str);
	return (final);
}

void	printp(t_print *data)
{
	char	*i;

	i = 0;
	if (data->sym == 'p')
	{
		i = ft_itoa_base_un(va_arg(data->arg, size_t), 16);
		i = smallchar(i);
		i = (((data->point && data->width == -1) || data->width\
					== 0) && ft_strcmp(i, "0") == 0) ?\
					"0x" : tagmakerp(data, i);
	}
	data->count += ft_strlen(i);
	ft_putstr(i);
	init_tag(data);
	if (ft_strcmp(i, "0x") != 0)
		free(i);
}
