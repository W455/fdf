# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 17:16:41 by oukrifa           #+#    #+#              #
#    Updated: 2017/05/12 01:32:35 by oukrifa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/


SOURCES =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
			\
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_atoi.c ft_tolower.c ft_toupper.c \
			\
			ft_putchar.c \
			ft_putendl.c ft_putnbr.c \
			ft_putstr.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c \
			\
			ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
			ft_strsub.c ft_strtrim.c \
			\
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
			ft_lstmap.c ft_lstnew.c \
			\
			ft_squareroot.c ft_isprime.c ft_factprime.c ft_power.c \
			ft_baseconvch.c ft_baseconvlo.c ft_atoi_base.c ft_factorial.c \
			\
			ft_pushstack.c ft_popstack.c ft_lengthstack.c ft_viewstack.c \
			ft_clearstack.c \

HEADERS = libft.h

OBJECTS = $(subst .c,.o,$(SOURCES))

WFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH), $(SOURCES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJECTS))
INC = $(addprefix -I, $(INC_PATH))


all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation .o :\033[36m OK\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Building libft.a :\033[36m OK\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(WFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "Deleting .o :\033[31m OK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting :\033[31m $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
