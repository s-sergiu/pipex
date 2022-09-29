# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/09/29 22:16:49 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
TEST = test
BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = pipex \
		utils \

BONUS_FILES = pipex_bonus \
			  utils_bonus \

GNL_FILES= get_next_line \
		   get_next_line_utils \

TEST_OBJ = ./obj/test.o
TEST_DIR = ./tests
LIBFT_OBJ = ./obj/libft.o
LIBFT_DIR = ./src/libft
PRINTF_OBJ= ./obj/libftprintf.o
PRINTF_DIR = ./src/ft_printf
GNL_DIR = ./src/gnl
GNL_OBJ = ./obj/gnl.o
OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
BONUS_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))
ALL_OBJS = $(PRINTF_OBJ) \
		   $(LIBFT_OBJ) \
		   $(OBJS) \
		   $(TEST_OBJ) \
		   $(BONUS_OBJ) \
		   $(GNL_OBJ) \

all: $(NAME)


$(TEST): $(TEST_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@echo "\033[0;34m"Building tests..
	@$(CC) $(FLAGS) $(TEST_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) -o $@
	@echo "\033[0;34m"Done.

$(BONUS): $(BONUS_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@echo "\033[1;35m"Building bonus..
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) -o $@
	@echo "\033[1;35m"Done.

$(GNL_OBJ): $(GNL_DIR)/*c
	@echo "\033[0;32m"Building gnl object files..
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/gnl.a ./obj/gnl.o
	@make fclean -C $(GNL_DIR)

$(TEST_OBJ): $(TEST_DIR)/*.c
	@$(CC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@echo "\033[0;32m"Building pipex..
	@echo "\033[0;32m"Done. 
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ) -o $@

$(LIBFT_OBJ): $(LIBFT_DIR)/*c
	@echo "\033[0;32m"Building libft object files..
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./obj/libft.o
	@make fclean -C $(LIBFT_DIR)

$(PRINTF_OBJ): $(PRINTF_DIR)/*c
	@echo "\033[0;32m"Building printf object files..
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a ./obj/libftprintf.o
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
	@$(RM) $(NAME) $(TEST) $(BONUS)
	@echo "\033[0;31m"Done.

.PHONY: bonus all clean fclean re
