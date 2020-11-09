/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:05:44 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 19:17:40 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*else_else_zero_d(t_print *data, char *final, char *str)
{
	if (data->flag->space)
	{
		data->tag->diff = ((ft_strcmp(str, "0") ==\
				0) && data->tag->diff != 0) ? data->\
				tag->diff - 1 : data->tag->diff;
		final[data->tag->i++] = ' ';
	}
	else if (data->flag->plus)
	{
		final[data->tag->i++] = '+';
		data->tag->diff = (data->tag->diff != 0)\
				? data->tag->diff - 1 : data->tag->diff;
	}
	else if (data->negative)
		final[data->tag->i++] = *str++;
	data->tag->count = data->tag->count + data->tag->diff;
	while (data->tag->diff != 0)
	{
		final[data->tag->i++] = '0';
		data->tag->diff--;
	}
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

char	*else_else_else_d(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->count + data->tag->diff;
	while (data->tag->diff != 0)
	{
		data->flag->space = 0;
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	if (data->flag->space)
		final[data->tag->i++] = ' ';
	else if (data->flag->plus)
		final[data->tag->i++] = '+';
	else if (data->negative)
		final[data->tag->i++] = *str++;
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

void	conf_final_d(t_print *data, char *final, char *str)
{
	if (data->point)
	{
		if (data->flag->minus)
			final = point_minus_d(data, final, str);
		else
			final = point_else_d(data, final, str);
	}
	else
	{
		if (data->flag->minus)
			final = else_minus_d(data, final, str);
		else
		{
			if (data->flag->zero)
				final = else_else_zero_d(data, final, str);
			else
				final = else_else_else_d(data, final, str);
		}
	}
}

char	*tagmakerint(t_print *data, char *str)
{
	char	*final;

	data->tag->count = ft_strlen(str);
	data->tag->count = (data->width >= data->tag->count)\
			? data->width : data->tag->count;
	data->tag->diff = (data->len >= data->tag->count)\
			? data->len - data->tag->count : 0;
	data->tag->count = (data->flag->space || data->flag->\
			plus || (data->negative && data->width >= data->\
			tag->count)) ? data->tag->count + 1 : data->tag->count;
	data->tag->withstr = ft_strlen(str);
	if (!(final = (char *)malloc(sizeof(char)\
			* (data->tag->diff + data->tag->count + 1))))
		return (NULL);
	conf_final_d(data, final, str);
	if (*str)
		free(str);
	return (final);
}

void	printint(t_print *data)
{
	char	*i;

	i = 0;
	if (data->spec->h)
		i = ft_itoa((short)va_arg(data->arg, int));
	else if (data->spec->hh)
		i = ft_itoa((signed char)va_arg(data->arg, int));
	else if (data->spec->z || data->spec->l || data->spec->j)
		i = ft_itoa_ul(va_arg(data->arg, long));
	else if (data->spec->ll)
		i = ft_itoa_un(va_arg(data->arg, long long));
	else
		i = ft_itoa(va_arg(data->arg, int));
	data->negative = foundchar(i, '-');
	if (data->negative == 1)
	{
		data->flag->space = 0;
		data->flag->plus = 0;
	}
	i = (((data->point && data->width == -1) ||\
			data->width == 0) && ft_strcmp(i, "0") == 0) ? "" : i;
	i = tagmakerint(data, i);
	data->count += ft_strlen(i);
	ft_putstr(i);
	free(i);
}
