NAME = so_long

PRINTF = libftprintf.a

MLX = libmlx_Linux.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long.h gnl/get_next_line.h

HEADER_BONUS = bonus/so_long_bonus.h

SRC = check_map.c init.c hooks.c read_map.c \
	  utils.c load_sprites.c gnl/get_next_line.c \
	  gnl/get_next_line_utils.c draw.c

SRC_BONUS = bonus/check_map_bonus.c bonus/init_bonus.c bonus/hooks_bonus.c bonus/read_map_bonus.c \
	  		bonus/utils_bonus.c bonus/load_sprites_bonus.c gnl/get_next_line.c \
	  		gnl/get_next_line_utils.c bonus/draw_bonus.c bonus/ft_itoa.c \
	  		bonus/enemy.c bonus/draw_enemy.c bonus/utils_bonus_2.c

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME) $(PRINTF) $(MLX)

$(MLX):
	make -C minilibx-linux

$(PRINTF):
	make -C printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(MLX)
	$(CC) $(OBJ) -Lprintf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(MLX) $(OBJ_BONUS) $(PRINTF) $(HEADER_BONUS)
	$(CC) $(OBJ_BONUS) -Lprintf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make -C printf clean
	make -C minilibx-linux clean

fclean: clean
	rm -rf $(NAME)
	make -C minilibx-linux clean
	make -C printf fclean

re: fclean all

.PHONY: clean fclean all re
