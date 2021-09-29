CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g
LIBFT = libft/libft.a
NAME = push_swap

SRCS = srcs/err_check.c srcs/free_all.c srcs/init.c srcs/list_act.c srcs/main.c

OBJS = err_check.o free_all.o init.o list_act.o main.o

INCLUDES = -I./includes

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(DEBUG) $(CFLAGS) -c $(SRCS) $(INCLUDES)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
