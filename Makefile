# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 11:31:30 by conoel            #+#    #+#              #
#    Updated: 2018/12/17 17:19:16 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ./includes/ft_printf.h

SRC_NAME = ft_printf.c get_args.c \
ft_itoa_base.c ft_itoa_baseh.c ft_itoa_basehh.c ft_itoa_basel.c \
ft_itoa_basell.c ft_bzero.c ft_itoa.c ft_strcmp.c ft_strlen.c ft_strcat2.c\
ft_memset.c ft_strdup.c ft_atoi.c ft_itoa_pointer.c ft_size_flags.c\
get_args2.c ft_itoa_float.c

SRC = $(addprefix ./srcs/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix ./obj/, $(OBJ_NAME))

.PHONY: clean fclean all re heil

all: obj $(NAME)

obj:
		@mkdir -p obj

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "Created Lib file ($(NAME)) !"

./obj/%.o: ./srcs/%.c
		@gcc -Wall -Wextra -Werror -c $< -o $@ -I$(HEADER)

clean:
		@rm -rf ./obj/*.o
		@echo "Removed all .o files"

fclean: clean
		@rm -rf $(NAME)
		@echo "Removed $(NAME) file"

re: fclean all

heil: all
		@gcc main.c $(NAME) -I$(HEADER)
		@echo "\n#>======= -- =======<#\n#       ~ ~~ ~       #\n#\033[31m\033[1m Heil Anne Franck ! \033[00m#\n#       ~ ~~ ~       #\n#>======= -- =======<#"
