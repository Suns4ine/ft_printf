/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally_func2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:02 by madan             #+#    #+#             */
/*   Updated: 2020/10/21 18:13:40 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char		*ft_strjoin_free(char *s1, char *s2, int indx)
{
	char	*new;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	if (indx == 1 || indx == 3)
		free(s1);
	if (indx == 2 || indx == 3)
		free(s2);
	return (new);
}

int			flag_check(const char flag)
{
	if (flag == ' ' || flag == '#' || flag == '+' || flag == '-' ||
			flag == '0')
		return (1);
	return (0);
}

t_print		flags(t_print *data, const char *format)
{
	int o;

	if (*format == '\0')
		return (*data);
	width_spec(data, format);
	format += data->step;
	o = data->step;
	number_spec(data, format);
	format += data->step - o;
	length_spec(data, format);
	return (*data);
}

void		width_spec(t_print *data, const char *format)
{
	while (flag_check(*(format + data->step)))
	{
		if (format[data->step] == '#')
			data->flag->hashtag = 1;
		if (format[data->step] == '+')
			data->flag->plus = 1;
		if (format[data->step] == '-')
			data->flag->minus = 1;
		if (format[data->step] == '0')
			data->flag->zero = 1;
		if (format[data->step] == ' ')
			data->flag->space = 1;
		data->step++;
	}
	if (data->flag->minus == 1)
		data->flag->zero = 0;
	if (data->flag->plus == 1)
		data->flag->space = 0;
}
