# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:27:48 by lhojoon           #+#    #+#              #
#    Updated: 2023/11/16 22:57:58 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR = srcs
SRCS = ./ft_printf.c \
		./puthexadecimal.c \
		./utoa.c \
		./implementations.c \
		./implementations2.c \
		./parser.c \
		./counter.c
OBJS = $(SRCS:c=o)
INCLUDES = ./includes
LIBFT = libft.a

all: $(NAME)
$(NAME): libftcompile $(OBJS) 
	ar rcs $(NAME) $(OBJS)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libftclean
	rm $(NAME) -f
	rm libft.a $(INCLUDES)/libft.h -f
re: fclean all
libftcompile:
	$(MAKE) -C libft
	@cp ./libft/libft.h $(INCLUDES)/libft.h
	@cp ./libft/libft.a ./libft.a
	@mv $(LIBFT) $(NAME)
libftclean:
	$(MAKE) fclean -C libft
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDES)