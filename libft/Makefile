#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 19:49:54 by cshawnee          #+#    #+#              #
#    Updated: 2020/03/16 17:29:13 by cshawnee         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_lstadd.c ft_memmove.c ft_strclr.c ft_strncmp.c ft_lstaddback.c ft_memset.c ft_strcmp.c ft_strncpy.c \
	ft_atoi.c ft_lstdel.c ft_node_fill.c ft_strcpy.c ft_strnequ.c ft_bzero.c ft_lstdelone.c ft_power.c ft_strdel.c	\
	ft_strnew.c ft_isalnum.c ft_lstiter.c ft_putchar.c ft_strdup.c ft_strnlen.c ft_isalpha.c ft_lstmap.c ft_putchar_fd.c \
	ft_strequ.c ft_strnstr.c ft_isascii.c ft_lstnb.c ft_putendl.c ft_striter.c ft_strrchr.c ft_ischar.c ft_lstnew.c \
	ft_putendl_fd.c ft_striteri.c ft_strsplit.c ft_isdigit.c ft_memalloc.c ft_putnbr.c ft_strjoin.c ft_strstr.c ft_islower.c \
	ft_memccpy.c ft_putnbr_fd.c ft_strlcat.c ft_strsub.c ft_isprint.c ft_memchr.c ft_putstr.c ft_strlen.c ft_strtrim.c \
	ft_isspace.c ft_memcmp.c ft_putstr_fd.c ft_strmap.c ft_tolower.c ft_isupper.c ft_memcpy.c ft_strcat.c ft_strmapi.c \
	ft_toupper.c ft_itoa.c ft_memdel.c ft_strchr.c ft_strncat.c get_next_line.c ft_itoa_un.c \
	ft_itoa_ul.c ft_itoa_base.c ft_itoa_base_un.c

OBJ = ft_lstadd.o ft_memmove.o ft_strclr.o ft_strncmp.o ft_lstaddback.o ft_memset.o ft_strcmp.o ft_strncpy.o \
	ft_atoi.o ft_lstdel.o ft_node_fill.o ft_strcpy.o ft_strnequ.o ft_bzero.o ft_lstdelone.o ft_power.o ft_strdel.o \
	ft_strnew.o ft_isalnum.o ft_lstiter.o ft_putchar.o ft_strdup.o ft_strnlen.o ft_isalpha.o ft_lstmap.o ft_putchar_fd.o \
	ft_strequ.o ft_strnstr.o ft_isascii.o ft_lstnb.o ft_putendl.o ft_striter.o ft_strrchr.o ft_ischar.o ft_lstnew.o \
	ft_putendl_fd.o ft_striteri.o ft_strsplit.o ft_isdigit.o ft_memalloc.o ft_putnbr.o ft_strjoin.o ft_strstr.o ft_islower.o \
	ft_memccpy.o ft_putnbr_fd.o ft_strlcat.o ft_strsub.o ft_isprint.o ft_memchr.o ft_putstr.o ft_strlen.o ft_strtrim.o \
	ft_isspace.o ft_memcmp.o ft_putstr_fd.o ft_strmap.o ft_tolower.o ft_isupper.o ft_memcpy.o ft_strcat.o ft_strmapi.o \
	ft_toupper.o ft_itoa.o ft_memdel.o ft_strchr.o ft_strncat.o get_next_line.o ft_itoa_un.o \
	ft_itoa_ul.o ft_itoa_base.o ft_itoa_base_un.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
