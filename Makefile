# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 11:05:03 by lhojoon           #+#    #+#              #
#    Updated: 2023/11/16 11:52:16 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

DIR = srcs
SRCS_RAW = main.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
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
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDES) $(MINILIBX_FLAGS)