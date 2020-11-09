/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_x2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:38:43 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 19:59:33 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*point_minus_x(t_print *data, char *final, char *str)
{
	if (data->flag->hashtag)
	{
		final[0] = '0';
		final[1] = (data->sym == 'x') ? 'x' : 'X';
		data->tag->i = 2;
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

char	*point_else_x(t_print *data, char *final, char *str)
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
		final[data->tag->i++] = (data->sym == 'x') ? 'x' : 'X';
		data->tag->count = data->tag->count - 2;
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

char	*else_minus_x(t_print *data, char *final, char *str)
{
	if (data->flag->hashtag)
	{
		final[0] = '0';
		final[1] = (data->sym == 'x') ? 'x' : 'X';
		data->tag->i = 2;
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

char	*else_else_else_x(t_print *data, char *final, char *str)
{
	data->tag->count = data->tag->count + data->tag->diff;
	while (data->tag->diff-- != 0)
		final[data->tag->i++] = ' ';
	if (data->flag->hashtag)
	{
		final[data->tag->i++] = '0';
		final[data->tag->i++] = (data->sym == 'x') ? 'x' : 'X';
	}
	while (data->tag->i < data->tag->count)
		final[data->tag->i++] = *str++;
	final[data->tag->i] = '\0';
	return (final);
}
