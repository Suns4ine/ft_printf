/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:03 by madan             #+#    #+#             */
/*   Updated: 2020/10/21 18:18:40 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	length_spec_h(t_print *data, const char *format)
{
	if (*format == 'h')
	{
		if (format[1] == 'h' && format++)
			data->spec->hh = 1;
		else
			data->spec->h = 1;
		data->step++;
		format++;
	}
	if (*format == 'j')
	{
		data->spec->j = 1;
		data->step++;
		format++;
	}
	if (data->spec->ll || data->spec->hh)
	{
		data->step++;
		format++;
	}
}

void	number_spec_point(t_print *data, const char *format)
{
	if (*format == '.')
	{
		data->point = 1;
		data->step++;
		data->flag->doc = 1;
		data->width = ft_atoi(&(*(format + 1)));
		data->width = (data->width <= 0) ? 0 : data->width;
		format++;
		while (*format == '-' || *format == '+')
		{
			data->step++;
			format++;
		}
		while (*format >= '0' && *format <= '9')
		{
			data->step++;
			format++;
		}
	}
}

void	conversion_spec(t_print *data)
{
	if (data->sym == 'i' || data->sym == 'd')
		printint(data);
	else if (data->sym == 'u' || data->sym == 'U')
		printuint(data);
	else if (data->sym == 's' || data->sym == 'c' || data->sym == '%')
		printchar(data);
	else if (data->sym == 'f' || data->sym == 'F')
		printfloat(data);
	else if (data->sym == 'x' || data->sym == 'X')
		printx(data);
	else if (data->sym == 'o')
		printo(data);
	else if (data->sym == 'p')
		printp(data);
}

void	length_spec(t_print *data, const char *format)
{
	if (*format == 'l')
	{
		if (format[1] == 'l' && format++)
			data->spec->ll = 1;
		else
			data->spec->l = 1;
		data->step++;
		format++;
	}
	if (*format == 'L')
	{
		data->spec->ldb = 1;
		data->step++;
		format++;
	}
	length_spec_h(data, format);
}

void	number_spec(t_print *data, const char *format)
{
	data->width = -1;
	data->len = 0;
	if (*format >= '1' && *format <= '9')
	{
		data->len = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			data->step++;
			format++;
		}
	}
	number_spec_point(data, format);
}
