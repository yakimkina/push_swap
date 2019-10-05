# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikole <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 16:49:00 by enikole           #+#    #+#              #
#    Updated: 2019/10/01 16:49:05 by enikole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
CHECKER_SRC = checker.c visualisation.c draw.c visual_args.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP = push_swap
PUSH_SWAP_SRC = push_swap.c five_sort.c list_max.c split_b.c split_a.c three_stack_a.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

SRC = instructions.c valid_arg.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

MLX = mlx

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(MLX) $(OBJ) $(LIB) $(CHECKER_OBJ)
	gcc -Wall -Wextra -Werror -o $(CHECKER) -I push_swap.h $(LIB) $(CHECKER_OBJ) $(OBJ) -L ./mlx -l mlx -framework OpenGL -framework AppKit

$(PUSH_SWAP): $(OBJ) $(LIB) $(PUSH_SWAP_OBJ)
	gcc -Wall -Wextra -Werror -o $(PUSH_SWAP) -I push_swap.h $(LIB) $(PUSH_SWAP_OBJ) $(OBJ)
%.o: %.c
	gcc -c $<
$(LIB):
	make -C ./libft
$(MLX):
	make -C ./mlx
clean:
	make clean -C ./libft
	rm -rf $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(OBJ)
fclean: clean
	make fclean -C ./libft
	rm -rf $(CHECKER) $(PUSH_SWAP)
re: fclean all
