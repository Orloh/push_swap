# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:19:15 by orhernan          #+#    #+#              #
#    Updated: 2026/01/05 19:07:15 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	:= all

# Directories
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
LIBFT_DIR	:= libft
PRINTF_DIR	:= ft_printf

# Files
NAME		:= push_swap.out
LIBFT		:= $(LIBFT_DIR)/libft.a
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

# Tools & Flags
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR) -g -O0
RM		:= rm -f
AR		:= ar rcs

# Source and object files
SRC		:= $(addprefix $(SRC_DIR)/,	\
		sort.c	parse.c	main_test.c	push_op.c	stack_init_dummy.c)
OBJ 		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Build Rules

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) all -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJ)
	printf "Creating $(NAME) ...\n"
	cp $(PRINTF) $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $@

# Targets
all: $(NAME)

clean:
	@printf "Cleaning up object files\n\n"
	$(MAKE) clean -C $(PRINTF_DIR) || true
	$(RM) -r $(OBJ_DIR)
	@printf "Removed object files\n"

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR) || true
	$(RM) $(NAME)
	@printf "Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re test
