/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:34:32 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 18:42:26 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*point_else_u(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->diff + data->tag->count;
	while (data->tag->diff != 0)
	{
		data->flag->space = 0;
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

char	*point_minus_u(t_print *data, char *final, char *str)
{
	if (data->negative)
	{
		final[data->tag->i++] = *str++;
		data->tag->withstr--;
	}
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	while (data->tag->diff-- != 0)
		final[data->tag->i++] = ' ';
	final[data->tag->i] = '\0';
	return (final);
}

void	conf_final_u(t_print *data, char *final, char *str)
{
	if (data->point)
	{
		if (data->flag->minus)
			final = point_minus_u(data, final, str);
		else
			final = point_else_u(data, final, str);
	}
	else
	{
		if (data->flag->minus)
			final = else_minus_u(data, final, str);
		else
			final = else_else_zero_u(data, final, str);
	}
}

char	*tagmakeruint(t_print *data, char *str)
{
	char *final;

	str = (data->width == 0) ? "" : str;
	data->tag->count = ft_strlen(str);
	data->tag->count = (data->width >= data->tag->count) ?\
						data->width : data->tag->count;
	data->tag->diff = (data->len >= data->tag->count) ?\
						data->len - data->tag->count : 0;
	data->tag->count = (data->flag->space\
						|| data->flag->plus || (data->negative\
						&& data->width >= data->tag->count)) ? data->tag->count\
						+ 1 : data->tag->count;
	data->tag->withstr = ft_strlen(str);
	if (!(final = (char *)malloc(sizeof(char) *\
						(data->tag->diff + data->tag->count + 1))))
		return (NULL);
	conf_final_u(data, final, str);
	if (*str)
		free(str);
	return (final);
}

void	printuint(t_print *data)
{
	char *i;

	i = 0;
	if (data->spec->h)
		i = ft_itoa((unsigned short)va_arg(data->arg, int));
	else if (data->spec->hh)
		i = ft_itoa((unsigned char)va_arg(data->arg, int));
	else if (data->spec->z || data->spec->l || data->spec->j)
		i = ft_itoa_for_u(va_arg(data->arg, unsigned long));
	else if (data->spec->ll)
		i = ft_itoa_uln(va_arg(data->arg, unsigned long long));
	else
		i = ft_itoa_for_u(va_arg(data->arg, unsigned int));
	data->negative = foundchar(i, '-');
	if (data->negative == 1)
	{
		data->flag->space = 0;
		data->flag->plus = 0;
	}
	i = tagmakeruint(data, i);
	data->count += ft_strlen(i);
	ft_putstr(i);
	free(i);
}
