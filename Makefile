#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 16:15:07 by cshawnee          #+#    #+#              #
#    Updated: 2020/10/31 16:23:46 by madan            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libftprintf.a

SRCS= src/additionally_func2.c ssrc/pecif_c2.c src/specif_f.c src/specif_o2.c src/specif_u2.c src/flags.c src/main.c \
		src/specif_d.c src/specif_f2.c src/specif_p.c src/specif_x.c \
		src/additionally_func.c src/specif_c.c src/specif_d2.c src/specif_o.c src/specif_u.c src/specif_x2.c

OBJECTS= src/additionally_func2.o src/specif_c2.o src/specif_f.o src/specif_o2.o src/specif_u2.o src/flags.o src/main.o \
		src/specif_d.o src/specif_f2.o src/specif_p.o src/specif_x.o \
		src/additionally_func.o src/specif_c.o src/specif_d2.o src/specif_o.o src/specif_u.o src/specif_x2.o

INCLUDES= ./inc

CFLAGS = -Wall -Wextra -Werror

CC= gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ./libft/ re
	@ar -rcs $(NAME) $(OBJECTS) ./libft/*.o
	@ranlib $(NAME)
%.o:%.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
clean:
	@make -C ./libft/ clean
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
