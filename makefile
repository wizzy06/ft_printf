# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparis <cparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 15:55:48 by cparis            #+#    #+#              #
#    Updated: 2017/03/27 20:42:41 by cparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

CFLAGS      = -Wall -Wextra -Werror

LIB_PATH	= ./includes

LIB = $(addprefix $(LIB_PATH)/, $(LIB_SRC))

LIB_SRC 	= ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c \
			ft_strrchr.c ft_strlen.c ft_strdup.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
			ft_strnew.c ft_strdel.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_memchr.c ft_memcmp.c \
			ft_strlcat.c ft_strstr.c ft_isalpha.c ft_toupper.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_strnstr.c ft_isascii.c ft_isprint.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_strupcase.c ft_strlowcase.c

PRINTF_DIR 	= ./srcs/
PRINTF_NAME	= ft_printf.c ft_reset.c ft_wintoa.c ft_get_num.c ft_prep_print.c ft_print.c \
	ft_print_num.c ft_print_space.c ft_print_str.c ft_print_wstr.c ft_itoa_base.c

PRINTF_SRC  = $(addprefix $(PRINTF_DIR)/, $(PRINTF_NAME))

LIB_OBJ 	= $(LIB_SRC:.c=.o)
PRINTF_OBJ 	= $(PRINTF_NAME:.c=.o)
OBJ         = $(addprefix $(LIB_OBJ)/, $(PRINTF_OBJ))

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(LIB) $(PRINTF_SRC)
	ar rc $(NAME) $(LIB_OBJ) $(PRINTF_OBJ)
	ranlib $(NAME)

clean:
	rm -f $(LIB_OBJ)
	rm -f $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all