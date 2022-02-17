NAME = so_long

PRINTF = libftprintf.a

MLX = libmlx_Linux.a

CC = cc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long.h gnl/get_next_line.h

SRC = check_map.c init.c hooks.c read_map.c \
	  utils.c load_sprites.c gnl/get_next_line.c \
	  gnl/get_next_line_utils.c draw.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(PRINTF) $(MLX)

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(MLX)
	$(CC) $(OBJ) -Lprintf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C minilibx-linux

$(PRINTF):
	make -C printf

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf printf/*.o

fclean: clean
	rm -rf $(NAME)
	rm -f minilibx-linux/libmlx_Linux.a
	rm -f minilibx-linux/libmlx.a
	rm -f printf/libftprintf.a

re: fclean all

.PHONY: clean fclean all re
