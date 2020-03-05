/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:29:10 by cshawnee          #+#    #+#             */
/*   Updated: 2020/03/02 14:16:53 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define F_HASHTAG (1 << 0)
# define F_SPACE (1 << 1)
# define F_PLUS (1 << 2)
# define F_MINUS (1 << 3)
# define F_ZERO (1 << 4)
# define F_WILDCARD (1 << 5)
# define F_UPPERCASE (1 << 6)
# define F_SHORT (1 << 7)
# define F_SHORTD (1 << 8)
# define F_LONG (1 << 9)
# define F_LONGD (1 << 10)
# define F_INTMAX (1 << 11)
# define F_SIZE_T (1 << 12)
# define F_MIN_LEN (1 << 13)
# define F_APP_PRECI (1 << 14)
# define F_POINTER (1 << 15)
# define BUFF_SIZE 1000

typedef struct		s_print
{
	char			*format;
	unsigned int	c;
	int				flag;
	int				len;//////////bytecount
	int				width;
	int				ooo;
	int				num;
	int				key;
	int 			pos;
	char			spec;
	int				pad;
	int				fd;
	int				step;
	char 			buff[BUFF_SIZE];
	va_list			arg;
	unsigned int	in;
	char			be_print[BUFF_SIZE];
}					t_print;

t_print flags(t_print *flags, const char *format);
void	conversion_specifier(t_print *key);
#endif
