/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:48:55 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 18:49:55 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*else_else_zero_o(t_print *data, char *final, char *str)
{
	if (data->flag->hashtag)
	{
		final[0] = '0';
		data->tag->i = 1;
	}
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

char	*else_else_else_o(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->count + data->tag->diff;
	while (data->tag->diff != 0)
	{
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	if (data->flag->hashtag)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

void	conf_final_o(t_print *data, char *final, char *str)
{
	if (data->point)
	{
		if (data->flag->minus)
			final = point_minus_o(data, final, str);
		else
			final = point_else_o(data, final, str);
	}
	else
	{
		if (data->flag->minus)
			final = else_minus_o(data, final, str);
		else
		{
			if (data->flag->zero)
				final = else_else_zero_o(data, final, str);
			else
				final = else_else_else_o(data, final, str);
		}
	}
}

char	*tagmakero(t_print *data, char *str)
{
	char	*final;

	data->tag->count = ft_strlen(str);
	data->tag->withstr = ft_strlen(str);
	data->tag->count = (data->width >= data->tag\
				->count) ? data->width : data->tag->count;
	data->tag->count = (data->flag->hashtag &&\
				data->width <= data->tag->withstr) ?\
				data->tag->count + 1 : data->tag->count;
	data->tag->diff = (data->len >= data->tag->count)\
				? data->len - data->tag->count : 0;
	if (!(final = (char *)malloc(sizeof(char\
				*) * (data->tag->diff + data->tag->count + 1))))
		return (NULL);
	conf_final_o(data, final, str);
	if (*str)
		free(str);
	return (final);
}

void	printo(t_print *data)
{
	char	*i;

	i = 0;
	if (data->spec->ll || data->spec->j || data->spec->l)
		i = ft_itoa_base_un(va_arg(data->arg, size_t), 8);
	else if (data->spec->hh)
		i = ft_itoa_base((unsigned char)va_arg(data->arg, int), 8);
	else if (data->spec->h)
		i = ft_itoa_base((unsigned short)va_arg(data->arg, int), 8);
	else
		i = ft_itoa_base_un(va_arg(data->arg, unsigned int), 8);
	i = (((data->point && data->width == -1) ||\
			data->width == 0) && ft_strcmp(i, "0") == 0) ? "" : i;
	data->flag->hashtag = (ft_strcmp(i, "0") == 0) ? 0 : data->flag->hashtag;
	i = tagmakero(data, i);
	data->count += ft_strlen(i);
	ft_putstr(i);
	free(i);
}
