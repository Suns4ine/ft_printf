/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_u2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:05:58 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:06:40 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*else_else_zero_u(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->count + data->tag->diff;
	if (data->flag->zero)
	{
		while (data->tag->diff-- != 0)
		{
			data->flag->space = 0;
			final[data->tag->i++] = '0';
		}
		while (data->tag->i < data->tag->count)
			final[data->tag->i++] = *str++;
	}
	else
	{
		while (data->tag->diff-- != 0)
		{
			data->flag->space = 0;
			final[data->tag->i++] = ' ';
		}
		while (data->tag->i < data->tag->count)
			final[data->tag->i++] = *str++;
	}
	final[data->tag->i] = '\0';
	return (final);
}

char	*else_minus_u(t_print *data, char *final, char *str)
{
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
