CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	so_long
RM				=	rm -rf
LMLX_M			=	-framework OpenGL -framework AppKit

RESET			=	\033[0m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
RED				=	\033[31m

SOURCE			=	so_long.c \
					./utils/map_check.c ./utils/ft_printf.c ./utils/s_utils.c ./utils/map_check2.c \
					./utils/function.c ./utils/image_utils.c ./utils/move_keys.c ./utils/map_check3.c
					

MINILIBX_MACOS	=	 ./library/minilibx_opengl/libmlx.a $(LMLX_M)

OBJECT			=	$(SOURCE:.c=.o)

C_MLXC			=	./library/minilibx_opengl/
					
all: 				$(NAME)

$(NAME):			$(OBJECT)
					make -C $(C_MLXC)
					@echo "$(YELLOW)Minilibx compiling...$(RESET)"
					@$(CC) $(CFLAGS) $(OBJECT) $(MINILIBX_MACOS) -o ${NAME}
					@echo "$(BLUE)Done...$(RESET)"			
					
clean:
					@echo "$(RED)Cleaned...$(RESET)"
					@make clean -C ./library/minilibx_opengl/
					@${RM} $(OBJECT)

fclean: 			clean
					@$(RM) ./minilibx_opengl/libmlx.a
					@${RM} so_long
					@echo "$(RED)Full Cleaned...$(RESET)"

re:					fclean $(NAME)

norm:			
					norminette *.[ch]

.PHONY:				all clean fclean re bonus