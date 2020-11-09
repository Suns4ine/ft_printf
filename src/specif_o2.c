/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_o2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:09:09 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:10:01 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*point_minus_o(t_print *data, char *final, char *str)
{
	{
		final[0] = '0';
		data->tag->i = 1;
	}
	while (data->tag->i < data->tag->count - data->tag->withstr)
		final[data->tag->i++] = '0';
	while (data->tag->i < data->tag->count)
	{
		final[data->tag->i] = *str++;
		data->tag->i++;
	}
	while (data->tag->diff != 0)
	{
		final[data->tag->i] = ' ';
		data->tag->i++;
		data->tag->diff--;
	}
	final[data->tag->i] = '\0';
	return (final);
}

char	*point_else_o(t_print *data, char *final, char *str)
{
	while (data->tag->diff != 0)
	{
		final[data->tag->i] = ' ';
		data->tag->i++;
		data->tag->diff--;
	}
	if (data->flag->hashtag)
	{
		final[data->tag->i++] = '0';
		data->tag->count = data->tag->count - 1;
	}
	while (data->tag->count - data->tag->withstr != 0)
	{
		final[data->tag->i++] = '0';
		data->tag->withstr++;
	}
	while (data->tag->count != 0)
	{
		final[data->tag->i++] = *str++;
		data->tag->count--;
	}
	final[data->tag->i] = '\0';
	return (final);
}

char	*else_minus_o(t_print *data, char *final, char *str)
{
	if (data->flag->hashtag)
	{
		final[0] = '0';
		data->tag->i = 1;
	}
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
