NAME		=	so_long
NAMEB		=	so_long_bonus
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
MLX			=	minilbx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./mandatory -I ./libft -I ./minilbx
INCB		=	-I ./bonus -I ./libft -I ./minilbx
LIB			=	-L ./libft -lft -L ./minilbx -lX11 -lXext -lm -lmlx -lbsd
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
SRC			=	mandatory/so_long.c \
				mandatory/moves.c \
				mandatory/images.c \
				mandatory/map.c \
				mandatory/initialize.c \
				mandatory/check_moves.c \
				mandatory/utils.c

SRCBONUS	=	bonus/bonus_so_long.c \
				bonus/bonus_moves.c \
				bonus/bonus_images.c \
				bonus/bonus_map.c \
				bonus/bonus_parts.c \
				bonus/bonus_initialize.c \
				bonus/bonus_check_moves.c \
				bonus/bonus_utils.c

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C mlx

$(LFT):
			@make -s -C libft

bonus:		$(MLX) $(LFT) $(NAMEB)

$(NAMEB):	$(OBJBONUS)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

bonus/%.o:	bonus/%.c
			@$(CC) $(FLAGS) $(INCB) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) src/*.o
			@rm -rf $(OBJBONUS) bonus/*.o

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@rm -rf $(NAMEB)

re:			fclean all
re_b:			fclean bonus

.PHONY:		all clean fclean re
