# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/09/28 01:32:39 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_printf \
		ft_itoa_unsigned \
		utils/printf_utils \
		utils/check_utils

LIBFT_OBJ= ../libft/libft.a
LIBFT_DIR = ../libft
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	@$(AR) $(NAME) $^

$(LIBFT_OBJ): $(LIBFT_DIR)/*c
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJS) $(LIBFT_OBJ)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
