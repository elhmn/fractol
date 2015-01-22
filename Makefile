NAME = fractol

SRC = main.c debug_01.c fractol_init.c check_errors.c fun_err_01.c \
		destroy_fract.c julia.c mandelbrot.c kleinian.c event_handle.c

OBJ = $(SRC:.c=.o)

OBJDIR = ./objs/

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

INCHOME = -I ./includes/ -I /usr/include/X11

INC = -I ./includes/ -I /usr/X11/include/X11

LIB42 = -L /usr/X11/lib

LIBHOME = -L /usr/lib64/X11

LIBFT = -L ./libft/

LIBS = -lft -lX11 -lXext -lmlx -lm

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(FLAGS) $(LIBFT) $(LIBHOME) -o $(NAME) $(OBJS) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(INCHOME) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	make fclean -C ./libft/

re: fclean all
