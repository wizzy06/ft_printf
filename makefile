# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparis <cparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 15:55:48 by cparis            #+#    #+#              #
#    Updated: 2017/03/17 18:46:05 by cparis           ###   ########.fr        #
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

SRCS_PRINTF = ft_conversion_master.c ft_get_number.c ft_get_params.c ft_itoa_base.c \
			ft_print_char.c ft_print_number.c ft_print_wchar.c ft_print_with_space.c \
			ft_printf.c ft_reset.c ft_wintoa.c

OPTIONS = -c -I $(INCLUDES)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo " ----------------------------------------------------------------"
	@echo "| MAKEFILE 1.0 USED FOR $(NAME) // PLEASE WAIT A MOMENT PLEASE |"
	@echo "|----------------------------------------------------------------|"
	@sleep 1.0;
	@echo "| \033[31m Making the project $(NAME) ==> 25% ...\033[m                      |"
	@gcc $(FLAGS) $(OPTIONS) $(SRCS)
	@ar rc libftprintf.a $(OBJ_LIBFT)
	@echo "| \033[31m Making the project $(NAME) ==> 50% ...\033[m                      |"
	@sleep 1.0;
	@echo "| \033[31m Making the project $(NAME) ==> 75% ...\033[m                      |"
	@gcc $(FLAGS) -o $(NAME) libftprintf.a $(SRCS_PRINTF)
	@sleep 1.0;
	@echo "| \033[31m Making the project $(NAME) ==> 100% ...\033[m                     |"
	@mkdir OBJ_DIR
	@mv *.o OBJ_DIR
	@sleep 1.0;
	@echo "|----------------------------------------------------------------|"
	@echo "| \033[33m         	      COMPILATION FINISHED   \033[m                    |"
	@echo " ----------------------------------------------------------------"
	@echo "\033[34m                         Better Makefile 1.0 by cparis - 42 School \033[m\n"

clean:
	@/bin/rm -f ./$(OBJ_LIBFT)
	@echo " ----------------------------------------------------------------"
	@echo "| MAKEFILE 1.0 USED FOR $(NAME) // PLEASE WAIT A MOMENT PLEASE |"
	@echo "|----------------------------------------------------------------|"
	@echo "| \033[31m Cleaning project $(NAME) ==> 50% ...\033[m                        |"
	@sleep 1.0;
	@echo "| \033[31m Cleaning project $(NAME) ==> 100% ...\033[m                       |"
	@rm -rf OBJ_DIR
	@sleep 1.0;
	@echo "|----------------------------------------------------------------|"
	@echo "| \033[36m           	        CLEAN FINISHED   \033[m                        |"
	@echo " ----------------------------------------------------------------"
	@echo "\033[34m                         Better Makefile 1.0 by cparis - 42 School \033[m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libftprintf.a

re: fclean all