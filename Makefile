NAME = so_long.out
SRC = main.c map.c image.c hooks.c window.c init.c enemy.c destroy.c count.c utils.c map_check.c map_check_contain.c map_create.c map_check_path.c
OBJ = $(SRC:.c=.o)

MLX = @mlx/Makefile.gen
PRINTF = @ft_printf/Makefile
LIBFT = @libft/Makefile
GNL = @gnl/Makefile
FLAGS = -Wall -Wextra -Werror
LIB = mlx/libmlx_Linux.a mlx/libmlx.a libft/libft.a ft_printf/libftprintf.a gnl/gnl.a
LINKS = -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(MLX) $(GNL) $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIB) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(MLX):
	@echo $(CURSIVE)$(GRAY) "     - Compiling Minilibx ..."
	@make -s -C mlx
	@echo $(GREEN)"- Minilibx ready -"

$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "     - Compiling Libft ..."
	@make -s -C libft
	@echo $(GREEN)"- Libft ready -"

$(GNL):
	@echo $(CURSIVE)$(GRAY) "     - Compiling GNL ..."
	@make -s -C gnl
	@echo $(GREEN)"- GNL ready -"

$(PRINTF):
	@echo $(CURSIVE)$(GRAY) "     - Compiling ft_printf ..."
	@make -s -C ft_printf
	@echo $(GREEN)"- ft_printf ready -"

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -s -C ft_printf clean
	@make -s -C mlx clean
	@make -s -C gnl clean
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -s -C ft_printf fclean
	@make -s -C mlx clean
	@make -s -C gnl fclean
	@make -s -C libft fclean

re: fclean all
