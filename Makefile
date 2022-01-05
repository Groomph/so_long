# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2022/01/05 23:29:20 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAMEB = so_long_bonus

CC = clang

CFLAGS = -Wall -Wextra -Werror

#CFLAGS = --analyze

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

LIBLINUX = -L $(LIB)/minilibx-linux/ -lmlx -lXext -lX11 -lm

HEADER = includes

HEADERB = includes_bonus

DIR_S = sources

DIR_O = temporary

DIR_SB = sources_bonus

DIR_OB = temporary_bonus

DIR_SP = sprites

SOURCES = main.c import_map.c is_walled.c draw_map.c \
	  display_shell.c image.c utils.c game.c hook.c \
	  $(DIR_SP)/ground.c $(DIR_SP)/wall.c \
	  $(DIR_SP)/egg.c $(DIR_SP)/player.c \
	  $(DIR_SP)/nest.c $(DIR_SP)/full_nest.c

SOURCESB = main.c import_map.c is_walled.c draw_map.c \
	  display_shell.c image.c utils.c game.c hook.c \
	  $(DIR_SP)/ground.c $(DIR_SP)/wall.c \
	  $(DIR_SP)/egg.c $(DIR_SP)/player.c \
	  $(DIR_SP)/nest.c $(DIR_SP)/full_nest.c \
	  $(DIR_SP)/numbers.c $(DIR_SP)/monster.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

SRCSB = $(addprefix $(DIR_SB)/,$(SOURCESB))

OBJSB = $(addprefix $(DIR_OB)/,$(SOURCESB:.c=.o))

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	make -C $(LIB)/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBLINUX)

$(NAMEB): $(OBJSB)
	make -C $(LIB)/libft
	make -C $(LIB)/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBFT) $(LIBLINUX)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/$(DIR_SP)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(DIR_OB)/%.o: $(DIR_SB)/%.c
	@mkdir -p $(DIR_OB)
	@mkdir -p $(DIR_OB)/$(DIR_SP)
	$(CC) $(CFLAGS) -I $(HEADERB) -o $@ -c $<

norme:
	@echo
	norminette $(LIB)/libft
	@echo
	norminette $(HEADER)/
	@echo
	norminette $(DIR_S)/
	@echo
	norminette $(HEADERB)/
	@echo
	norminette $(DIR_SB)/

clean:
	rm -rf $(DIR_O)
	rm -rf $(DIR_OB)
	make fclean -C $(LIB)/libft
	make clean -C $(LIB)/minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus norme
