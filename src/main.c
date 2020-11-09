/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:32:39 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/28 19:32:42 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	init_tag(t_print *data)
{
	data->tag->diff = 0;
	data->tag->count = 0;
	data->tag->withstr = 0;
	data->tag->i = 0;
}

void	initial(t_print *data)
{
	data->step = 0;
	data->flag->minus = 0;
	data->flag->zero = 0;
	data->flag->plus = 0;
	data->flag->space = 0;
	data->flag->hashtag = 0;
	data->flag->doc = 0;
	data->point = 0;
	data->nul = 0;
	data->spec->ll = 0;
	data->spec->l = 0;
	data->spec->h = 0;
	data->spec->hh = 0;
	data->spec->z = 0;
	data->spec->j = 0;
	data->spec->ldb = 0;
	data->count = 0;
	init_tag(data);
}

int		ret(t_print *word, int count)
{
	free(word->flag);
	free(word->spec);
	free(word->tag);
	va_end(word->arg);
	return (count);
}

void	ft_malloc_word(t_print *word)
{
	word->flag = (t_flag *)malloc(sizeof(t_flag));
	word->spec = (t_spec *)malloc(sizeof(t_spec));
	word->tag = (t_tag *)malloc(sizeof(t_tag));
}

int		ft_printf(const char *format, ...)
{
	t_print	word;
	int		count;

	ft_malloc_word(&word);
	va_start(word.arg, format);
	count = 0;
	initial(&word);
	while (*format)
	{
		if (*format != '%' && *format)
		{
			ft_putchar(*format++);
			count++;
			continue;
		}
		word = (*format) ? flags(&word, ++format) : (flags(&word, format));
		word.sym = *(format + word.step);
		if (!word.sym)
			return (ret(&word, count));
		conversion_spec(&word);
		format += word.step + 1;
		count += word.count;
		initial(&word);
	}
	return (ret(&word, count));
}
