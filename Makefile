# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 12:33:41 by akilk             #+#    #+#              #
#    Updated: 2022/03/10 15:45:05 by akilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c\
	read.c\
	draw.c\
	bresenham.c\

OBJS = $(subst .c,.o,$(SRCS))

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -I libft
LINKS = -L libft\
	-I fdf.h -L minilibx\
	-l mlx -l ft -framework OpenGL -framework Appkit

MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(SRCS) -o $(NAME) $(FLAGS) $(LINKS)
	@echo "$(MSG)Done!$(END)"

$(OBJS): $(LIBFT) $(SRCS)
	@echo "$(MSG)Compiling...$(END)"
	@gcc $(FLAGS) -c $(SRCS)

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "$(MSG)Objects removed!$(END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(MSG)Targets removed!$(END)"

re: fclean all
