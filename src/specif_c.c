/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:15:13 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 19:29:41 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*minus_c(t_print *data, char *final, char *str, char percent)
{
	if (data->flag->minus == 1)
	{
		while (data->tag->i < data->tag->withstr)
		{
			final[data->tag->i] = str[data->tag->i];
			data->tag->i++;
		}
		while (data->len-- != 0)
			final[data->tag->i++] = percent;
		final[data->tag->i] = '\0';
	}
	else
	{
		while (data->tag->i < data->len)
			final[data->tag->i++] = percent;
		while (data->tag->withstr != 0)
		{
			final[data->tag->i++] = *str++;
			data->tag->withstr--;
		}
		final[data->tag->i] = '\0';
	}
	return (final);
}

void	*dop_tagmakerchar(t_print *data, char *str)
{
	if (data->tag->count == -1 && data->sym == 's')
	{
		str = "(null)";
		data->tag->count = ft_strlen(str);
	}
	str = (data->tag->count == -1 && data->\
			sym == 'c' && data->flag->hashtag) ? "0" : str;
	if (data->flag->doc)
		data->tag->withstr = (data->tag->count >\
			data->width) ? data->width : data->tag->count;
	else
		data->tag->withstr = data->tag->count;
	data->tag->withstr = (data->sym == 'c' ||\
			data->sym == '%') ? 1 : data->tag->withstr;
	data->len = (data->len >= data->tag->withstr)\
			? data->len - data->tag->withstr : 0;
	return (str);
}

char	*tagmekerchar(t_print *data, char *str)
{
	char	*final;
	char	percent;

	percent = (data->sym == '%' && data->flag->zero == 1) ? '0' : ' ';
	data->tag->count = ft_strlen(str);
	str = dop_tagmakerchar(data, str);
	if (!(final = (char *)malloc(sizeof(char *)\
			* (data->len + data->tag->withstr + 1))))
		return (NULL);
	if (data->nul && data->sym == 'c')
		final = null_c(data, final, percent);
	else
		final = minus_c(data, final, str, percent);
	return (final);
}

void	str_write(t_print *data, char *str, char i)
{
	str = tagmekerchar(data, str);
	if (data->sym == 'c' && i == 0)
	{
		data->count += 1;
		data->count += ft_strlen(str);
	}
	else
		data->count += ft_strlen(str);
	if (data->sym == 'c' && i == 0)
	{
		if (data->flag->minus)
		{
			write(1, &i, 1);
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			write(1, &i, 1);
		}
	}
	else
		ft_putstr(str);
	free(str);
}

void	printchar(t_print *data)
{
	char	*str;
	char	i;

	i = '\0';
	if (data->sym == 's')
		str = va_arg(data->arg, char*);
	else if (data->sym == '%')
		str = "%";
	else
	{
		i = (char)va_arg(data->arg, int);
		if (i != 0)
		{
			str = ft_strnew(0);
			str[0] = i;
			str[1] = '\0';
		}
		else
		{
			str = "";
			data->nul = 1;
		}
	}
	str_write(data, str, i);
}
