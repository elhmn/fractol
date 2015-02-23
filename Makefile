# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/06 19:40:37 by bmbarga           #+#    #+#              #
#    Updated: 2015/02/23 11:34:45 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c debug_01.c fractol_init.c check_errors.c fun_err_01.c \
		destroy_fract.c julia.c mandelbrot.c mandel_cube.c event_handle.c \
		fractol_init_02.c draw.c color.c event_handle_2.c \
		draw_2.c fractol_init_03.c init_color.c event_handle_3.c

OBJ = $(SRC:.c=.o)

OBJDIR = ./objs/

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

INCHOME = -I ./includes/ -I  /usr/include/x11

INC = -I ./includes/ -I /usr/x11/include/x11

LIB42 = -L /usr/x11/lib

LIBHOME = -L /usr/lib64/x11

LIBFT = -L ./libft/

LIBS = -lft -lx11 -lxext -lmlx -lm

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(FLAGS) $(LIBFT) $(LIB42) -o $(NAME) $(OBJS) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(INC) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

home: obj
	make -C ./libft/
	$(CC) $(FLAGS) $(LIBFT) $(LIBHOME) -o $(NAME) $(OBJS) $(LIBS)

obj: $(SRCS)
	$(CC) $(FLAGS) $(INCHOME) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ)
	make clean -C ./libft/

fclean: clean
	make fclean -C ./libft/
	rm $(NAME)

re: fclean all
