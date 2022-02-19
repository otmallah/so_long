NAME = so_long

NAME_B = so_long_bonus

CC = @gcc 


CFLAGS = -Wall -Werror -Wextra

AR = ar -rc

RM = @rm -f

FILES =  so_long.c get/get_next_line.c check_map/check_size.c  \
		check_map/complete_wall.c check_map/ft_window.c check_map/key_event.c \
		check_map/number_line_in_map.c check_map/position.c  size_window/size_height.c \
		size_window/size_width.c  mouvement/mouve_down.c mouvement/mouve_left.c \
		mouvement/mouve_right.c mouvement/mouve_up.c check_map/complete_map.c utils/itoa.c \
		complete.c Ft_printf/ft_printf.c  Ft_printf/ft_decimal.c Ft_printf/ft_putnbr_fd.c Ft_printf/ft_nbrlen_int.c \
		Ft_printf/ft_putchar_fd.c Ft_printf/ft_print_all.c Ft_printf/ft_putstr_fd.c \
		Ft_printf/ft_print_str.c

BS = so_long_bonus.c get/get_next_line.c check_map_bonnus/check_size_bonnus.c \
	check_map_bonnus/complete_wall_bonnus.c check_map_bonnus/ft_window_bonnus.c \
	check_map_bonnus/key_event_bonnus.c  check_map_bonnus/position_bonus.c \
	check_map_bonnus/number_line_in_map_bonnus.c size_window/size_height.c \
	size_window/size_width.c mouvement_bonus/mouve_down_bonus.c mouvement_bonus/mouve_left_bonus.c \
	mouvement_bonus/mouve_right_bonus.c mouvement_bonus/mouve_up_bonus.c positin_enemy/position_K.c\
	utils/itoa.c animation/animation.c animation/animation2.c animation/enemy_animation.c  \
	check_map_bonnus/complete_map_bonus.c complete_bonus.c complete_bonus2.c \
	Ft_printf/ft_printf.c  Ft_printf/ft_decimal.c Ft_printf/ft_putnbr_fd.c Ft_printf/ft_nbrlen_int.c \
	Ft_printf/ft_putchar_fd.c Ft_printf/ft_print_all.c Ft_printf/ft_putstr_fd.c \
	Ft_printf/ft_print_str.c


# Colors
C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_GREEN = \033[1;32m
C_BLUE = \033[1;34m
C_L_BLUE = \033[1;34m
C_WHITE = \033[1;37m
C_RES = \033[0m


all : $(NAME)

$(NAME) : $(FILES)
	$(CC) $(FLAGS) $(FILES) libmlx.dylib -o $(NAME)
	@echo "$(C_GREEN)[LIBRARY CREATED!]$(C_RES)"

clean :
	$(RM) $(NAME)
	@echo "$(C_RED)[OBJECT DELETED!]$(C_RES)"

fclean : clean
	$(RM) $(NAME) $(NAME_B)
	@echo "$(C_RED)[LIBFT.A REMOVED!]$(C_RES)"

bonus : $(NAME_B)

$(NAME_B) : $(BS) 	
	$(CC) $(FLAGS) $(BS) libmlx.dylib -o $(NAME_B)
	@echo "$(C_L_BLUE)[BONUS CREATED!]$(C_RES)"

re : fclean all

rebonus : fclean bonus