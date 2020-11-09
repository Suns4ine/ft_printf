/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:23:06 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 18:59:30 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*ft_ftoa(double value, int width)
{
	return (ft_ftoa_long(value, width));
}

char	*else_f(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->diff + data->tag->count;
	while (data->tag->diff)
	{
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	if (data->negative)
		final[data->tag->i++] = *str++;
	if (data->flag->plus)
		final[data->tag->i++] = '+';
	if (data->flag->space)
		final[data->tag->i++] = ' ';
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

char	*minus_f(t_print *data, char *final, char *str)
{
	if (data->negative)
		final[data->tag->i++] = *str++;
	if (data->flag->plus)
		final[data->tag->i++] = '+';
	if (data->flag->space)
		final[data->tag->i++] = ' ';
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	while (data->tag->diff)
	{
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	final[data->tag->i] = '\0';
	return (final);
}

char	*tagmakerfloat(t_print *data, char *str)
{
	char	*final;

	data->tag->count = ft_strlen(str);
	data->tag->withstr = ft_strlen(str);
	data->tag->count = (data->width >= data->\
				tag->count) ? data->width : data->tag->count;
	data->tag->count = (data->flag->plus || data->\
				flag->space) ? data->tag->count + 1 : data->tag->count;
	data->tag->diff = (data->len >= data->tag->\
				count) ? data->len - data->tag->count : 0;
	if (!(final = (char *)malloc(sizeof(char)\
				* (data->tag->diff + data->tag->count + 1))))
		return (NULL);
	if (data->flag->minus)
		final = minus_f(data, final, str);
	else
		final = else_f(data, final, str);
	if (*str)
		free(str);
	return (final);
}

void	printfloat(t_print *data)
{
	char	*i;

	i = 0;
	i = (data->spec->ldb) ? ft_ftoa_long(va_arg(data->arg,\
				long double), data->width) : ft_ftoa(va_arg(data->\
				arg, double), data->width);
	data->negative = foundchar(i, '-');
	if (data->negative == 1)
	{
		data->flag->space = 0;
		data->flag->plus = 0;
	}
	i = tagmakerfloat(data, i);
	data->count += ft_strlen(i);
	ft_putstr(i);
	free(i);
}
