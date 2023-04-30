NAME =		cub3D

INC_DIR = 	$(shell find includes -type d)

SRC_DIR = 	$(shell find srcs -type d)

OBJ_DIR	= obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

vpath %.h $(foreach dir, $(INC_DIR), $(dir):)

SRC =	exits.c					\
		map_check.c				\
		get_map.c				\
		get_next_line.c			\
		get_next_line_utils.c	\
		set_images.c			\
		set_screen.c			\
		ft_itoa.c				\
		ft_split.c				\
		ft_atoi.c				\
		2Dvectors.c				\
		data_map_resize.c		\
		wall_find.c				\
		create_img.c			\
		math_main.c				\
		print_error.c			\
		fnc_utils.c				\
		moves.c					\
		textures.c				\
		init.c					\
		drawing.c				\
		rotations.c				\
		main.c		

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

CFLAGS =	-Wall -Wextra -Werror -Lminilibx -lmlx -lX11 -lXext -lm -g

IFLAGS =	$(foreach dir, $(INC_DIR), -I $(dir))

CC =	gcc

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./minilibx
		$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	make -C ./minilibx clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
