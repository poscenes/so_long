NAME = so_long

PRINTF = libftprintf.a

MLX = libmlx_Linux.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long_bonus.h ../gnl/get_next_line.h

SRC = check_map_bonus.c init_bonus.c hooks_bonus.c read_map_bonus.c \
	  utils_bonus.c load_sprites_bonus.c ../gnl/get_next_line.c \
	  ../gnl/get_next_line_utils.c draw_bonus.c ft_itoa.c \
	  enemy.c draw_enemy.c utils_bonus_2.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(PRINTF) $(MLX)

$(MLX):
	make -C ../minilibx-linux

$(PRINTF):
	make -C ../printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(MLX)
	$(CC) $(OBJ) -L../printf -lftprintf -L../minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C ../printf clean
	make -C ../minilibx-linux clean

fclean: clean
	rm -rf $(NAME)
	make -C ../minilibx-linux clean
	make -C ../printf fclean

re: fclean all

.PHONY: clean fclean all re
