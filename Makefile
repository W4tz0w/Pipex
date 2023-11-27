# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 17:37:59 by daddy_cool        #+#    #+#              #
#    Updated: 2023/11/27 12:25:31 by daddy_cool       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for Pipex

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Source files
SRC = ft_pipex.c ft_pipex_utils.c

# Object files
OBJ = $(SRC:.c=.o)

# Targets
TARGET = pipex

# Libft
LIBFTDIR = ./Libft
LIBFT = $(LIBFTDIR)/libft.a

# Rule to build the target
$(TARGET): $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -o $@ $^ $(LIBFT)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to clean files
clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

# Phony target to clean files and executable
fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFTDIR) fclean

# Phony target to recompile
re: fclean all

# Phony target to build all
all: $(TARGET)

.PHONY: all clean fclean re
