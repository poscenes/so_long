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

all: $(NAME) $(PRINTF)

$(PRINTF):
	make -C ../printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF)
	$(CC) $(OBJ) -L../printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C ../printf clean

fclean: clean
	rm -rf $(NAME)
	make -C ../printf fclean

re: fclean all

.PHONY: clean fclean all re
