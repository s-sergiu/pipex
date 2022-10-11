# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/10/11 15:42:31 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = bonus

CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -f

FILES = pipex \
		init \
		input_parser \
		checkers \
		free_utils \

BONUS_FILES = pipex_bonus \
			  input_parser_bonus \
			  checkers_bonus \
			  free_utils_bonus \
			  init_bonus \
			  heredoc \
			  error_messages \

GNL_FILES= get_next_line \
		   get_next_line_utils \

LIBFT_OBJ = ./obj/libft.o
LIBFT_DIR = ./src/libft
PRINTF_OBJ= ./obj/libftprintf.o
PRINTF_DIR = ./src/ft_printf
GNL_DIR = ./src/gnl
GNL_OBJ = ./obj/gnl.o
BONUS_DIR = ./obj/bonus/
OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
BONUS_OBJ = $(addprefix $(BONUS_DIR), $(addsuffix .o, $(BONUS_FILES)))
ALL_OBJS = $(PRINTF_OBJ) \
		   $(LIBFT_OBJ) \
		   $(OBJS) \
		   $(BONUS_OBJ) \
		   $(GNL_OBJ) \

all: $(NAME)

$(BONUS): $(BONUS_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) include/pipex_bonus.h
	@echo "\033[1;35m"Removing pipex mandatory binary..
	@echo Building bonus..
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) -o pipex
	@echo "\033[1;35m"Done.
	@echo "██████╗░██╗██████╗░███████╗██╗░░██╗  ██████╗░░█████╗░███╗░░██╗██╗██╗░░░██╗░██████╗"
	@echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝  ██╔══██╗██╔══██╗████╗░██║██║██║░░░██║██╔════╝"
	@echo "██████╔╝██║██████╔╝█████╗░░░╚███╔╝░  ██████╦╝██║░░██║██╔██╗██║██║██║░░░██║╚█████╗░"
	@echo "██╔═══╝░██║██╔═══╝░██╔══╝░░░██╔██╗░  ██╔══██╗██║░░██║██║╚████║██║██║░░░██║░╚═══██╗"
	@echo "██║░░░░░██║██║░░░░░███████╗██╔╝╚██╗  ██████╦╝╚█████╔╝██║░╚███║██║╚██████╔╝██████╔╝"
	@echo "╚═╝░░░░░╚═╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝  ╚═════╝░░╚════╝░╚═╝░░╚══╝╚═╝░╚═════╝░╚═════╝░"

$(GNL_OBJ): $(GNL_DIR)/*c
	@echo "\033[0;32m"Building gnl object files..
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/gnl.a ./obj/gnl.o
	@make fclean -C $(GNL_DIR)

$(NAME): $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) include/pipex.h
	@echo "\033[0;32m"Building pipex..
	@echo "\033[0;32m"Done. 
	@echo "██████╗░██╗██████╗░███████╗██╗░░██╗"
	@echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	@echo "██████╔╝██║██████╔╝█████╗░░░╚███╔╝░"
	@echo "██╔═══╝░██║██╔═══╝░██╔══╝░░░██╔██╗░"
	@echo "██║░░░░░██║██║░░░░░███████╗██╔╝╚██╗"
	@echo "╚═╝░░░░░╚═╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) -o $@

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

./obj/bonus/%.o:./src/bonus/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

./obj/%.o:./src/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "\033[0;31m"Removing printf object files..
	@echo "\033[0;31m"Removing libft object files..
	@$(RM) $(ALL_OBJS) 
	@echo "\033[0;31m"Done.

fclean: clean
	@echo "\033[0;31m"Removing binary..
	@$(RM) $(NAME) $(BONUS)
	@echo "\033[0;31m"Done.

re: clean all

.PHONY: bonus all clean fclean re
