# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 13:53:47 by conoel            #+#    #+#              #
#    Updated: 2018/11/15 14:03:11 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft.h

SRCS = ft_bzero.c ft_memcpy.c ft_memccpy.c ft_iscntrl.c ft_isgraph.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strlen.c \
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_islower.c ft_isupper.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isspace.c ft_isalpha.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_isspace.c ft_isblank.c ft_memset.c\

all: $(NAME)

$(NAME) :
	@gcc -Wall -Werror -Wextra -c $(SRCS) -I$(HEADER)
	@ar r $(NAME) *.o
	@ranlib $(NAME)
	@echo "Lib created !"

.PHONY: clean
clean :
	@rm -f *.o
	@echo ".o Removed"

.PHONY: fclean
fclean : clean
	@rm -f $(NAME)
	@echo "Lib file removed"

.PHONY: re
re : fclean all

heil : re clean
	@echo "Heil Anne Franck !!!"
