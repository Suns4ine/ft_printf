/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:33:23 by cshawnee          #+#    #+#             */
/*   Updated: 2020/10/29 15:28:12 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_tag
{
	int			diff;
	int			count;
	int			withstr;
	int			i;
}				t_tag;

typedef struct	s_flag
{
	int			hashtag;
	int			space;
	int			plus;
	int			minus;
	int			zero;
	int			doc;
}				t_flag;

typedef struct	s_spec
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			z;
	int			j;
	int			ldb;
}				t_spec;

typedef struct	s_print
{
	char		*format;
	t_flag		*flag;
	t_spec		*spec;
	t_tag		*tag;
	char		sym;
	int			byte;
	va_list		arg;
	int			step;
	int			len;
	int			width;
	int			negative;
	int			count;
	int			point;
	int			nul;
}				t_print;

t_print			flags(t_print *data, const char *format);
void			conversion_spec(t_print *data);
char			*ft_newstrcat(char *s1, const char *s2);
char			*bigchar(char *str);
char			*smallchar(char *str);
int				foundchar(char *str, char c);
void			printx(t_print *data);
char			*tagmakerx(t_print *data, char *str);
void			conf_final_x(t_print *data, char *final, char *str);
char			*else_else_zero_x(t_print *data, char *final, char *str);
char			*else_else_else_x(t_print *data, char *final, char *str);
char			*else_minus_x(t_print *data, char *final, char *str);
char			*point_else_x(t_print *data, char *final, char *str);
char			*point_minus_x(t_print *data, char *final, char *str);
void			printuint(t_print *data);
char			*tagmakeruint(t_print *data, char *str);
void			conf_final_u(t_print *data, char *final, char *str);
char			*point_minus_u(t_print *data, char *final, char *str);
char			*point_else_u(t_print *data, char *final, char *str);
char			*else_minus_u(t_print *data, char *final, char *str);
char			*else_else_zero_u(t_print *data, char *final, char *str);
void			printp(t_print *data);
char			*tagmakerp(t_print *data, char *str);
void			printo(t_print *data);
char			*tagmakero(t_print *data, char *str);
void			conf_final_o(t_print *data, char *final, char *str);
char			*else_else_else_o(t_print *data, char *final, char *str);
char			*else_else_zero_o(t_print *data, char *final, char *str);
char			*else_minus_o(t_print *data, char *final, char *str);
char			*point_else_o(t_print *data, char *final, char *str);
char			*point_minus_o(t_print *data, char *final, char *str);
void			printfloat(t_print *data);
char			*tagmakerfloat(t_print *data, char *str);
char			*minus_f(t_print *data, char *final, char *str);
char			*else_f(t_print *data, char *final, char *str);
char			*ft_ftoa(double value, int width);
char			*ft_ftoa_long(long double value, int width);
int				approximator(char *fract, double value);
void			printint(t_print *data);
char			*tagmakerint(t_print *data, char *str);
void			conf_final_d(t_print *data, char *final, char *str);
char			*else_else_else_d(t_print *data, char *final, char *str);
char			*else_else_zero_d(t_print *data, char *final, char *str);
char			*else_minus_d(t_print *data, char *final, char *str);
char			*point_else_d(t_print *data, char *final, char *str);
char			*dop_point_else_d(t_print *data, char *final, char *str);
char			*point_minus_d(t_print *data, char *final, char *str);
char			*dop_point_minus_d(t_print *data, char *final, char *str);
void			printchar(t_print *data);
void			str_write(t_print *data, char *str, char i);
char			*tagmekerchar(t_print *data, char *str);
void			*dop_tagmakerchar(t_print *data, char *str);
char			*minus_c(t_print *data, char *final, char *str, char percent);
char			*null_c(t_print *data, char *final, char percent);
char			*ft_stradd(char *str, char ch);
char			*ft_strjoin_free(char *s1, char *s2, int indx);
char			*ft_strjoin_free(char *s1, char *s2, int indx);
int				flag_check(const char flag);
void			length_spec(t_print *data, const char *format);
void			width_spec(t_print *data, const char *format);
void			number_spec(t_print *data, const char *format);
void			init_tag(t_print *data);

#endif
