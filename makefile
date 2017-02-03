# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparis <cparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 15:55:48 by cparis            #+#    #+#              #
#    Updated: 2017/02/03 13:16:25 by cparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf

INCLUDES = ./libft/libft.h

SRC_PATH = ./libft/

SRC_LIBFT = ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c \
			ft_strrchr.c ft_strlen.c ft_strdup.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
			ft_strnew.c ft_strdel.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_memchr.c ft_memcmp.c \
			ft_strlcat.c ft_strstr.c ft_isalpha.c ft_toupper.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_strnstr.c ft_isascii.c ft_isprint.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

SRCS = $(addprefix $(SRC_PATH)/, $(SRC_LIBFT))

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

SRCS_PRINTF = ft_printf.c

OPTIONS = -c -I $(INCLUDES)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(OPTIONS) $(SRCS)
	@ar rc libft.a $(OBJ_LIBFT)
	@gcc $(FLAGS) -o $(NAME) libft.a $(SRCS_PRINTF)
	@echo 'Compilation de FillIt en cours ...'
	@echo 'Compilation TERMINE !'

clean:
	@/bin/rm -f ./$(OBJ_LIBFT)
	@echo 'Suppression des fichiers .o en cours ..'
	@echo 'Suppression TERMINE !'

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a

re: fclean all