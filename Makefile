
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./inc/

LIBFT_PATH = ./libft
LIBFT = ./libft/libft.a
MLX_PATH = ./mlx
MLX = ./mlx/libmlx.a

MLX_FLAG = -Lmlx -lmlx -lX11 -lXext -lm

RM = rm -f

SRC_PATH = ./src/

SRC = main.c map.c render_move.c render.c set.c valid_map.c utils.c tracking.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(SRCS:.c=.o)

all: subs $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subs:
	@$(MAKE) -C $(MLX_PATH) all
	@$(MAKE) -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(MLX) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
