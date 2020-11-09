/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:49:16 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:01:01 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*else_else_zero_x(t_print *data, char *final, char *str)
{
	if (data->flag->zero)
	{
		if (data->flag->hashtag)
		{
			final[0] = '0';
			final[1] = (data->sym == 'x') ? 'x' : 'X';
			data->tag->i = 2;
		}
		data->tag->count = data->tag->count + data->tag->diff;
		while (data->tag->diff-- != 0)
			final[data->tag->i++] = '0';
		while (data->tag->i < data->tag->count)
			final[data->tag->i++] = *str++;
		final[data->tag->i] = '\0';
	}
	else
		final = else_else_else_x(data, final, str);
	return (final);
}

void	conf_final_x(t_print *data, char *final, char *str)
{
	if (data->point)
	{
		if (data->flag->minus)
			final = point_minus_x(data, final, str);
		else
			final = point_else_x(data, final, str);
	}
	else
	{
		if (data->flag->minus)
			final = else_minus_x(data, final, str);
		else
			final = else_else_zero_x(data, final, str);
	}
}

char	*tagmakerx(t_print *data, char *str)
{
	char	*final;

	str = (data->sym == 'X') ? bigchar(str) : smallchar(str);
	data->tag->count = ft_strlen(str);
	data->tag->withstr = ft_strlen(str);
	data->tag->count = (data->width >= data->tag->count) ?\
						data->width : data->tag->count;
	data->tag->count = (data->flag->hashtag) ?\
						data->tag->count + 2 : data->tag->count;
	data->tag->diff = (data->len >= data->tag->count) ?\
						data->len - data->tag->count : 0;
	if (!(final = (char *)malloc(sizeof(char *) *\
						(data->tag->diff + data->tag->count + 1))))
		return (NULL);
	conf_final_x(data, final, str);
	if (*str)
		free(str);
	return (final);
}

void	printx(t_print *data)
{
	char	*i;

	i = 0;
	if (data->spec->ll || data->spec->j || data->spec->l)
		i = ft_itoa_base_un(va_arg(data->arg, size_t), 16);
	else if (data->spec->hh)
		i = ft_itoa_base((unsigned char)va_arg(data->arg, int), 16);
	else if (data->spec->h)
		i = ft_itoa_base((unsigned short)va_arg(data->arg, int), 16);
	else
		i = ft_itoa_base_un(va_arg(data->arg, unsigned int), 16);
	data->flag->hashtag = (ft_strcmp(i, "0") == 0) ? 0 : data->flag->hashtag;
	i = (((data->point && data->width == -1) || data->width == 0)\
			&& ft_strcmp(i, "0") == 0) ? "" : i;
	i = tagmakerx(data, i);
	data->count += ft_strlen(i);
	ft_putstr(i);
	free(i);
}
