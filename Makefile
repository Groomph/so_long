# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2021/10/27 16:03:48 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror #--analyze

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

LIBLINUX = -L $(LIB)/minilibx-linux/ -lmlx -lXext -lX11 -lm

HEADER = includes

DIR_S = sources

DIR_SP = sprites

DIR_O = temporary

SOURCES = main.c import_map.c flood_fill.c display_shell.c draw_map.c \
	  wall.c $(DIR_SP)/blocks1.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	make -C $(LIB)/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBLINUX)

$(NAMEB): $(OBJSB)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/$(DIR_SP)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@echo
	norminette $(LIB)/libft
	@echo
	norminette $(HEADER)/
	@echo
	norminette $(DIR_S)/

clean:
	rm -rf $(DIR_O)
	make fclean -C $(LIB)/libft
	make clean -C $(LIB)/minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus norme
