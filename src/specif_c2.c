/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_c2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:22:54 by madan             #+#    #+#             */
/*   Updated: 2020/10/28 20:24:00 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*null_c(t_print *data, char *final, char percent)
{
	while (data->len != 0)
	{
		final[data->tag->i++] = percent;
		data->len--;
	}
	final[data->tag->i] = '\0';
	return (final);
}
