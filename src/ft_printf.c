/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <cshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:10:56 by cshawnee          #+#    #+#             */
/*   Updated: 2020/03/17 12:09:21 by cshawnee         ###   ########.fr       */
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

////////////////////////////////////////////////////////////////////
void ft_swap(char *t1, char *t2)
{
	char tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

char *with_red(char *str, char *sign, t_print *flags)
{
	int len;
	char *c;
	char *gen;
	c = ft_strchr(str, '.');
	if (flags->spec == 'f' || !c)
	{
		len = ft_strlen(str);
		len = (sign) ? len - 1 : len;
	}
	else
		len = ft_strlen(c) - 1;
/*
	write(1, "!", 1);
	ft_putnbr(flags->width);
	write(1, "!", 1);
	ft_putnbr(len);
	write(1, "!", 1);
*/
	if (flags->width > len)
	{
		gen = ft_strnew(flags->width - len);
		ft_memset(gen, '0', flags->width - len);
		gen = (flags->spec != 'f') ? ft_strjoin(gen, str) : ft_strjoin(str, gen);
		if (sign)
			ft_swap(ft_strchr(gen, '-'), gen);
		return (gen);
	}
	return (str);
}

char *len_red(char *str, char *sign, t_print *flags)
{
	int len;
	char *gen;
	len = ft_strlen(str);
	if (len < flags->len)
	{
		gen = ft_strnew(flags->len - len);
		ft_memset(gen, flags->ooo, flags->len - len);
		if (flags->spec == 'd' && flags->in & F_SPACE && flags->ooo == '0' && sign == 0)
			gen[0] = ' ';
		str = (flags->in & F_MINUS || flags->spec == 'p') ? ft_strjoin(str, gen) : ft_strjoin(gen, str);
//		sign = ft_strchr(str, '-'); //////
		if (sign && flags->ooo == '0')
			ft_swap(str, sign);
		if(flags->in & F_HASHTAG && flags->ooo == '0' && (gen = ft_strchr(str, 'x')))
			ft_swap(gen, str + 1);
		if (sign == 0 && flags->in & F_PLUS && flags->ooo == '0' && (flags->spec == 'd' || flags->spec == 'f'))
		{
//			write(1, ")", 1);			
			ft_swap(ft_strchr(str, '0'), ft_strchr(str,  '+'));
		}
	}
	else if(flags->in & F_SPACE && (flags->spec == 'd' || flags->spec == 'f') && sign == 0)
		str = ft_strjoin(" ", str);
	return (str);
}

//////////////////////////////////////////////////////////////////

char *hash_red(char *str, t_print *flags)
{
	if (!ft_strcmp(str, "0") && !(flags->in & F_POINTER))
		return (str);
	if (!ft_strcmp(str, "0") && flags->in & F_POINTER &&  !flags->width)
		str[0] = '\0';
	if (flags->spec == 'x' || flags->spec == 'p')
		return (ft_strcat("0x", str));
	else if (flags->spec == 'o')
		return (ft_strcat("0", str));
	return (str);
}

char *tagmaker(t_print *key, char *str)
{
	char *sign;
	sign = ft_strchr(str, '-');
	str = with_red(str, sign, key);
	if (key->in & F_HASHTAG || key->in & F_POINTER)
		str = hash_red(str, key);
	if (key->width == 0 && ft_strcmp(str, "0") && (key->spec == 'x' || key->spec == 'o' || key->spec == 'd') && !(key->in & F_HASHTAG && key->spec == 'o'))
		str[0] = '\0';
	if (sign == 0 && key->in & F_PLUS && (key->spec == 'd' || key->spec == 'f'))
	{
//		write(1, "(", 1);
		str = ft_strjoin("+", str);
	}
	key->ooo = (key->width != -1 && key->spec != 'f') ? ' ' : key->ooo;
	str = len_red(str, sign, key);
	return (str);
}

void	printfloat(t_print *key)
{
	    char *i;
		i = 0;
		if (key->spec == 'f')
		{
			key->width = (key->width == -1) ? 6 : key->width;
			if (key->in & F_LONGD)
			{	
				i = ft_itoa_ul(va_arg(key->arg, long double));
				i = tagmaker(key, i);
			}
			else
			{
				i = ft_itoa(va_arg(key->arg, double));
				i = tagmaker(key, i);
			}
		}
		ft_putstr(i);
}

void	printhexol(t_print *key)
{
	char *i;
    i = 0;
	if (key->spec == 'x' || key->spec == 'X')
	{
		i = (key->in & F_LONGD || key->in &  F_INTMAX) ? ft_itoa_base_un(va_arg(key->arg, size_t), 16) : ft_itoa_base(va_arg(key->arg, int), 16);////////////////// 
		i = tagmaker(key, i);
//		if (key->spec == 'X')
//			ft_strupper(i);
	}
	else if (key->spec == 'o')
	{	
		i = (key->in & F_LONGD || key->in &  F_INTMAX) ? ft_itoa_base_un(va_arg(key->arg, size_t), 8) : ft_itoa_base(va_arg(key->arg, int), 8);//////////////////
		i = tagmaker(key, i);
	}
    ft_putstr(i);
}

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
	else if(key->in & F_LONGD)
		i = ft_itoa_un(va_arg(key->arg, unsigned int));
	else
		i = ft_itoa(va_arg(key->arg, int));
	i = tagmaker(key, i);
	ft_putstr(i);
}
void	conversion_specifier(t_print *key)
{
	char *i;
	i = 0;
//	write(1, &key->spec, 1);
	if (key->spec == 'i' || key->spec == 'd' || key->spec == 'u')
		printint(key);
	if (key->spec == 'f' || key->spec == 'F' || key->spec == 'a' || key->spec == 'A')
		printfloat(key);
	else if (key->spec == 'x' || key->spec == 'X' || key->spec == 'o')
		printhexol(key);
}

int main()
{
    char *t = "qwerty";
	ft_printf("one %d, two %f, three %x\n",
			  1, 2.0, 15);
    return(0);
}
