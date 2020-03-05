/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:10:56 by cshawnee          #+#    #+#             */
/*   Updated: 2020/03/04 18:13:12 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	t_print     word;
	char *s;
	int bytecount;

	s = (char *)format;
	va_start(word.arg, format);
	bytecount = 0;
	word.step = 0;
	while (*format)
	{
		if (*format != '%' && *format)
		{
             ft_putchar(*format++);
			 bytecount++;
			 continue;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{				
			ft_putchar(*format++);
			bytecount++;
			continue;
		}
		word = (*format) ? flags(&word, ++format) : (flags(&word, format));///flags check
		word.spec = *(format + word.step);
		conversion_specifier(&word);
		format += word.step + 1;
		word.step = 0;
		va_end(word.arg);
	}
	return(bytecount);
}
/*
char *tagmaker(t_print *flags, char *str)
{
OK
}
*/

void	printint(t_print *key)
{
	char *i;
	i = 0;
	if (key->in & F_SHORT)
		i = ft_itoa((short)va_arg(key->arg, int));
	else if(key->in & F_SHORTD)
		i = ft_itoa((signed char)va_arg(key->arg, int));
	else if(key->in & F_SIZE_T || key->in & F_LONG || key->in & F_INTMAX)
		i = ft_itoa_ul(va_arg(key->arg, long));
//	else if(key->in & F_LONGD)
//		i = ft_itoa_un(va_arg(key->arg, unsigned int));
	else
		i = ft_itoa(va_arg(key->arg, int));
//	i = tegmaker(key, i);
	ft_putstr(i);
}
void	conversion_specifier(t_print *key)
{
	char *i;
	i = 0;
	if (key->spec == 'i' || key->spec == 'd' || key->spec == 'u')
	{
		printint(key);
//		write(1, "OK", 2);
	}
}

int main()
{
    char *t = "qwerty";
    ft_printf("here come a number %+##lld and one more %+-+hi, and last %#hhi", 4, 2, 17);
    return(0);
}
