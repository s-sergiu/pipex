# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/09/28 04:29:49 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS =	pipex_bonus
TEST = test

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = pipex \
		utils \

TEST_OBJ = ./obj/test.o
TEST_DIR = ./tests
LIBFT_OBJ = ./obj/libft.a
LIBFT_DIR = ./src/libft
PRINTF_OBJ= ./obj/libftprintf.a
PRINTF_DIR = ./src/ft_printf
OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
ALL_OBJS = $(PRINTF_OBJ) \
		   $(LIBFT_OBJ) \
		   $(OBJS) \
		   $(TEST_OBJ) \

all: $(NAME)

$(TEST): $(TEST_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@echo "\033[0;34m"Building tests..
	@$(CC) $(FLAGS) $(TEST_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) -o $@
	@echo "\033[0;34m"Done.

$(TEST_OBJ): $(TEST_DIR)/*c
	@$(CC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ) $(PRINTF_DIR)
	@echo "\033[0;32m"Done. 
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ) -o $@

$(LIBFT_OBJ): $(LIBFT_DIR)/*c
	@echo "\033[0;32m"Building object files..
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./obj/libft.a
	@make fclean -C $(LIBFT_DIR)

$(PRINTF_OBJ): $(PRINTF_DIR)/*c
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a ./obj/libftprintf.a
	@make fclean -C $(PRINTF_DIR)

./obj/%.o:./src/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "\033[0;31m"Removing printf object files..
	@echo "\033[0;31m"Removing libft bject files..
	@$(RM) $(ALL_OBJS) 
	@echo "\033[0;31m"Done.

fclean: clean
	@echo "\033[0;31m"Removing binary..
	@$(RM) $(NAME) $(TEST)
	@echo "\033[0;31m"Done.

.PHONY: bonus all clean fclean re
