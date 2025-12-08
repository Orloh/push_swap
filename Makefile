# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:19:15 by orhernan          #+#    #+#              #
#    Updated: 2025/12/08 01:19:55 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj
TEST_DIR	= .test
LIBFT_DIR	= libft

# Files
NAME		= push_swap
LIBFT		= $(LIBFT_DIR)/libft.a

# Tools & Flags
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -MD -I$(INC_DIR) -I$(LIBFT_DIR) -g -O0
RM		= rm -f
AR		= ar rcs
PRINTF		= printf

# Source and object files
SRC		= $(addprefix $(SRC_DIR)/,)
OBJ 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP		= $(OBJ:.o=.d)

# Build Rules
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(PRINTF) "Creating $(NAME) ...\n"
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

# Targets

clean:
	@$(PRINTF) "Cleaning up object files\n\n"
	$(MAKE) clean -C $(LIBFT_DIR) || true
	$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "Removed object files\n"

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) || true
	$(MAKE) clean -C $(TEST_DIR)
	$(RM) $(NAME)
	@$(PRINTF) "Removed $(NAME)\n"

re: fclean all

test: all
	$(MAKE) all -C $(TEST_DIR)

.PHONY: all clean fclean re test
