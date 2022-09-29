# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/09/29 21:20:54 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = get_next_line \
		get_next_line_utils \

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) 
	@$(AR) $(NAME) $^

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
