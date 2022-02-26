NAME = so_long

PRINTF = libftprintf.a

MLX = libmlx_Linux.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long.h gnl/get_next_line.h

SRC = check_map.c init.c hooks.c read_map.c \
	  utils.c load_sprites.c gnl/get_next_line.c \
	  gnl/get_next_line_utils.c draw.c ft_itoa.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(PRINTF) $(MLX)

$(MLX):
	make -C minilibx-linux

$(PRINTF):
	make -C printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(MLX)
	$(CC) $(OBJ) -Lprintf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C printf clean
	make -C minilibx-linux clean

fclean: clean
	rm -rf $(NAME)
	make -C minilibx-linux clean
	make -C printf fclean

re: fclean all

.PHONY: clean fclean all re
