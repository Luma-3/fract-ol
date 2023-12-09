
CC = gcc
NAME = fractol.out

SRC = main.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror
OBJFLAGS = $(CFLAGS) -I/usr/include -Imlx_linux -O3
NAMEFLAGS = $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(OBJFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(NAMEFLAGS) -o $(NAME)


all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

