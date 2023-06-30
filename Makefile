NAME = so_long

CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -g
LFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MLX = ./minilibx-linux/libmlx.a
GNL =  get_next_line/*c
GNLOBJS = $(GNL:.c=.o)

SRCS = main.c	readmap.c	mapcontrol.c	rendermap.c	move_player.c	
OBJS = $(SRCS:.c=.o)


all : $(MLX) $(NAME)

$(MLX) :
	make -sC ./Libft
	make -sC ./ft_printf
	make -sC ./minilibx-linux

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc -g $(OBJS) $(GNLOBJS) $(LFLAGS) ./Libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	
	make clean -C ./minilibx-linux
	make fclean -C ./libft
	make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re
