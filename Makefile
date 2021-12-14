# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 20:11:51 by oholgado          #+#    #+#              #
#    Updated: 2021/12/03 13:01:09 by oholgado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
CFLAGS = -Wall -Werror -Wextra 
MLXFLAGS = -lmlx -framework OPENGL -framework Appkit
RM = rm -rf

SRC_DIR = src/
BONUS_DIR = bonus/

SRCS = so_long.c so_long_utils.c so_long_errors.c so_long_errors01.c \
		ft_get_data.c init.c keyhook.c movements.c \

SRCS_BONUS = so_long_bonus.c so_long_utils_bonus.c so_long_errors_bonus.c \
		   so_long_errors01_bonus.c ft_get_data_bonus.c ft_itoa_bonus.c \
			init_bonus.c keyhook_bonus.c movements_bonus.c \
			animation_bonus.c enemy_bonus.c movement_enemy_bonus.c \
			keyhook01_bonus.c animation01_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(SRC_DIR) $(OBJS)	
	@ $(MAKE) -s -C mlx
	@ mv mlx/libmlx.a .
	@ $(CC) $(CFLAGS) $(addprefix $(SRC_DIR), $(OBJS)) -L . $(MLXFLAGS) -o $(NAME)
	@ printf "\n\e[1;32mThe mandatory is ready\e[0m\n\n"

$(OBJS): $(addprefix $(SRC_DIR), $(SRCS))
	@ $(CC) $(CFLAGS) -Imlx -c $^
	@ mv $(OBJS) $(SRC_DIR)

$(OBJS_BONUS): $(addprefix $(BONUS_DIR), $(SRCS_BONUS))
	@ $(CC) $(CFLAGS) -Imlx -c $^
	@ mv $(OBJS_BONUS) $(BONUS_DIR)

bonus: $(BONUS_DIR) $(OBJS_BONUS)
	@ $(MAKE) -s -C mlx
	@ mv mlx/libmlx.a .
	@ $(CC) $(CFLAGS) $(addprefix $(BONUS_DIR), $(OBJS_BONUS)) -L . $(MLXFLAGS) -o $(NAME)
	@ printf "\n\e[1;32mThe bonus is ready\e[0m\n\n"

clean:
	@ $(RM) mlx/liblmlx.a
	@ $(RM) $(addprefix $(SRC_DIR), $(OBJS)) $(addprefix $(BONUS_DIR), $(OBJS_BONUS))
	@ printf "\n\e[1;35mFiles ./src/*.0 & ./bonus/*.o deleted\e[0m\n\n"
	
re: fclean all

fclean: clean
	@ $(RM) $(NAME)
	@ $(RM) libmlx.a
	@ $(MAKE) -C mlx/ clean
	@ printf "\n\e[1;31mFiles ./src/*.0 & ./bonus/*.o & libmlx.a and ./mlx/*.o deleted\e[0m\n\n"

.PHONY: all re clean fclean bonus
