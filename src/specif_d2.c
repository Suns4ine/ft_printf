/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:19:34 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:20:17 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*dop_point_minus_d(t_print *data, char *final, char *str)
{
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	while (data->tag->diff-- != 0)
		final[data->tag->i++] = ' ';
	final[data->tag->i] = '\0';
	return (final);
}

char	*point_minus_d(t_print *data, char *final, char *str)
{
	if (data->negative)
	{
		final[data->tag->i++] = *str++;
		data->tag->withstr--;
		data->tag->diff = (data->tag->diff != 0 &&\
				(data->width >= (int)ft_strlen(str)))\
				? data->tag->diff - 1 : data->tag->diff;
	}
	else if (data->flag->plus)
	{
		final[data->tag->i++] = '+';
		data->tag->diff = (data->tag->diff != 0)\
				? data->tag->diff - 1 : data->tag->diff;
	}
	else if (data->flag->space && data->tag->diff == 0)
	{
		final[data->tag->i++] = ' ';
		data->tag->withstr++;
	}
	final = dop_point_minus_d(data, final, str);
	return (final);
}

char	*dop_point_else_d(t_print *data, char *final, char *str)
{
	if (data->flag->space)
		final[data->tag->i++] = ' ';
	else if (data->flag->plus)
		final[data->tag->i++] = '+';
	else if (data->negative)
	{
		final[data->tag->i++] = *str++;
		data->tag->withstr--;
	}
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}

char	*point_else_d(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->diff + data->tag->count;
	data->tag->withstr = (data->tag->diff != 0 &&\
				(data->flag->plus || data->negative))\
				? data->tag->withstr + 1 : data->tag->withstr;
	data->tag->diff = (data->tag->diff != 0 && (data->\
				flag->plus || (data->negative && data->width >=\
				(int)ft_strlen(str)))) ? data->tag->diff - 1 : data->tag->diff;
	while (data->tag->diff != 0)
	{
		data->tag->withstr = (data->flag->space == 1)\
				? data->tag->withstr + 1 : data->tag->withstr;
		data->flag->space = 0;
		final[data->tag->i++] = ' ';
		data->tag->diff--;
	}
	final = dop_point_else_d(data, final, str);
	return (final);
}

char	*else_minus_d(t_print *data, char *final, char *str)
{
	if (data->flag->space && data->tag->diff == 0)
		final[data->tag->i++] = ' ';
	else if (data->flag->plus)
		final[data->tag->i++] = '+';
	else if (data->negative)
		final[data->tag->i++] = *str++;
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
