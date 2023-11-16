CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./ft_putnbr_fd.c \
		./ft_putendl_fd.c \
		./ft_putstr_fd.c \
		./ft_putchar_fd.c \
		./ft_striteri.c \
		./ft_strmapi.c \
		./ft_itoa.c \
		./ft_atoi.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_split.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_strjoin.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strncmp.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strtrim.c \
		./ft_substr.c \
		./ft_tolower.c \
		./ft_toupper.c  \
		./ft_strlcat.c
SRCB =	./ft_lstnew.c \
		./ft_lstadd_front.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstadd_back.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c
OBJS = $(SRCS:c=o)
OBJB = $(SRCB:c=o)
INCLUDES = ./
NAME = libft.a

all: $(OBJS) $(NAME)
$(NAME):
	ar rcs $(NAME) $(OBJS)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean
	rm $(NAME) -f
re: fclean all
bonus: $(OBJS) $(OBJB)
	ar rcs $(NAME) $(OBJS) $(OBJB)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) -I $(INCLUDES)