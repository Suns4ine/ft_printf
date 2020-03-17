/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:15:00 by cshawnee          #+#    #+#             */
/*   Updated: 2020/03/09 17:01:37 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int flag_check(const char flag)
{
    if (flag == ' ' || flag == '#' || flag == '+' || flag == '-' || flag == '0')
        return (1);
    return (0);
}

void    width_spec(t_print *key, const char *format)
{
    while (flag_check(*format))
    {
//      write(1, "^", 1);
        if (format[key->step] == '#')
            key->in |= F_HASHTAG;
        if (format[key->step] == '+')
            key->in |= F_PLUS;
/*      if (key->num == (int)va_arg(key->arg,int) < 0)
    {
        key->in |= F_MINUS;
        key->num *= (-1);
    }
*/  if (format[key->step] == '-')
			key->in |= F_MINUS;
		if (format[key->step] == '0')
			key->in |= F_ZERO;
		if (format[key->step] == ' ')
			key->in |= F_SPACE;
		format++;
		key->step++;
    }
	if (key->in & F_MINUS)
		key->in ^= F_ZERO;
	if (key->in & F_PLUS)
		key->in ^= F_SPACE;
	key->ooo = (key->in & F_ZERO) ? '0' : ' ';////////////////// check ooo -> (key->in)
//  printf("%d", key->step);
}

void    numbers_spec(t_print *flags, const char *format)
{
	flags->width = -1;
    if (*format >= '1' && *format <= '9')
    {
        flags->len = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			flags->step++;
			format++;
		}
    }
    if (*format == '.')
    {
        flags->step += (*format == '.') ? 1 : 0;
		flags->width = ft_atoi(&(*(format + 1)));
		format++;
        while (*format >= '0' && *format <= '9')
        {
            flags->step++;
            format++;
		}
    }
}

void length_spec(t_print *key, const char *format)
{
		if (*format == 'l')
		{
			key->in |= (format[1] == 'l' && format++) ? F_LONGD : F_LONG;
			key->step++;
			format++;
		}
		if (*format == 'h')
		{
			key->in |= (format[1] == 'h' && format++) ? F_SHORTD : F_SHORT;
			key->step++;
			format++;
		}
		if (*format == 'z')
		{			
			key->in |= F_SIZE_T;
			key->step++;
			format++;
		}
		if (*format == 'j')
		{
			key->in |= F_INTMAX;
			key->step++;
			format++;
		}
		if (key->in & F_LONGD || key->in & F_SHORTD)
		{		
			format++;
			key->step++;
		}
//      if (ft_strchr("X", *format))
    //      key->in |= (*format != 'X') ? F_LONG : F_UPPERCASE;
}

t_print flags(t_print *flags, const char *format)
{

	int o;

    flags->in = 0; // bzero
//  flag->len = 0;
    if (*format == '\0')
		return (*flags);
//  write(1, "!", 1);
    width_spec(flags, format);
//  write(1, "!", 1);
	format += flags->step;
	o = flags->step;
	numbers_spec(flags, format);
//  write(1, "!", 1);
	format += flags->step - o;
    length_spec(flags, format);
//flags->step++;
//  printf("%d", flags->step);
//  flags->spec = *format;
//	format += flags->step;
    return (*flags);
}
