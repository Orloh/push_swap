# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:19:15 by orhernan          #+#    #+#              #
#    Updated: 2026/01/19 18:30:40 by orhernan         ###   ########.fr        #
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
TEST_NAME	:= test_push_swap.out
LIBFT		:= $(LIBFT_DIR)/libft.a
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

# Tools & Flags
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR) -g -O0
RM		:= rm -f
AR		:= ar rcs

# Source and object files
SRC		:= $(addprefix $(SRC_DIR)/,	\
		sort.c		\
		parse.c		\
		stack.c		\
		push_op.c	\
		swap_op.c	\
		rotate_op.c	\
		sort_stub.c	\
		reverse_rotate_op.c)
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
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(OBJ) $(PRINTF) -o $@

$(TEST_NAME): $(SRC_DIR)/main_test.c $(PRINTF) $(OBJ)
	printf "Creating $(TEST_NAME)...\n"
	$(CC) $(CFLAGS) $< $(OBJ) $(PRINTF) -o $@

# Targets
all: $(NAME)

test: $(TEST_NAME)
	./$<

clean:
	@printf "Cleaning up object files\n\n"
	$(MAKE) clean -C $(PRINTF_DIR) || true
	$(RM) -r $(OBJ_DIR)
	@printf "Removed object files\n"

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR) || true
	$(RM) $(NAME) $(TEST_NAME)
	@printf "Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re test
