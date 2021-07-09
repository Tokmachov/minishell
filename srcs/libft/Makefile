# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 17:16:27 by sjolynn           #+#    #+#              #
#    Updated: 2020/11/27 13:17:58 by hrema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_OF_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c ft_minints.c ft_maxints.c ft_abs.c \
get_next_line.c ft_lst_to_arr.c ft_free_str_arr.c \
ft_realloc.c ft_assert.c ft_str_arr_len.c ft_str_arr_dup.c ft_isnum_str.c

HEADER_LIBFT = libft.h

OBJS_LIBFT = $(patsubst %.c, %.o, $(SRCS_OF_LIBFT))

OBJS = $(OBJS_LIBFT)

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c $(HEADER_LIBFT)
	$(CC) $(CFLAGS) -I. -g $< -o $@

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

