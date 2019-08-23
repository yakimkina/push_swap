# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikole <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 19:20:12 by enikole           #+#    #+#              #
#    Updated: 2019/08/23 23:54:14 by enikole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h \
	get_next_line.h \
	libft.h

HEADERDIR = /includes/

SRC = f_beauty.c \
	f_fraction.c \
	f_integer.c \
	f_second_addend.c \
	f_summ.c \
	ft_atoi_long.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_ib.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa_base.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_str_is_lowercase.c \
	ft_str_is_uppercase.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strlowcase.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_strupcase.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_uib.c \
	ft_wordcount.c \
	fun_csp.c \
	fun_di.c \
	fun_f.c \
	fun_flags.c \
	fun_format.c \
	fun_uo.c \
	fun_x.c \
	get_next_line.c \
	initialization.c \
	mod.c \
	trash.c \
	x_trash.c

OBJ = $(SRC:%.c=%.o)

all : $(LIBRARY)

$(LIBRARY) : $(OBJ)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $(SRC)
	ar rc $(LIBRARY) $(OBJ)
	ranlib $(LIBRARY)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
