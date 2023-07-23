# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elevy <elevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 16:58:11 by elevy             #+#    #+#              #
#    Updated: 2023/07/08 17:49:31 by elevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := srcs
SRC_FILES := algorithm_utils.c  \
             algorithm_utils2.c \
             main.c             \
             push_swap.c        \
             stack_utils.c      \
             push_utils.c       \
             push.c             \
             swap.c             \
             rotate.c           \
             rev_rotate.c       \
             short_stack.c      \
             short_utils.c      \
             utils.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ = $(SRC:.c=.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INC := $(LIBFT_DIR)/includes

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(LIBFT_INC)

NAME := push_swap

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(NAME) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
