NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

HEADER = ft_printf.h

SRC = ft_printf.c ft_printf_utils_1.c \
	ft_printf_utils_2.c ft_printf_utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
