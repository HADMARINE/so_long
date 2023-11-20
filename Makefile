# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 11:05:03 by lhojoon           #+#    #+#              #
#    Updated: 2023/11/17 17:06:11 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -I/usr/include -Imlx_linux
# -Imlx_linux -I/usr/include
# -I/usr/include -Imlx-linux/lib -lmlx-linux/libmlx_Linux.a

DIR = srcs
SRCS_RAW = main.c \
			get_next_line.c \
			get_next_line_utils.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft

LIBFT = libft.a
MINILIBX_A = mlx_linux/libmlx_Linux.a

all: $(NAME)
$(NAME): libftcompile minilibxcompile $(OBJS) 
# $(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX_A) $(MINILIBX_FLAGS) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
	$(CC) $(OBJS) -Llibft -l:libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libftclean minilibxclean
	rm $(NAME) -f
re: fclean all
libftcompile:
	$(MAKE) -C libft
libftclean:
	$(MAKE) fclean -C libft
minilibxcompile:
	$(MAKE) -C mlx_linux
minilibxclean:
	$(MAKE) clean -C mlx_linux
%.o: %.c
	$(CC) -c $< -o $@ $(MINILIBX_FLAGS) $(CFLAGS) $(INCLUDES)