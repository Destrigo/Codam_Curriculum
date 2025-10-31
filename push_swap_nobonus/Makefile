CC = cc
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
NAME = push_swap
OBJS =  files/main.o					\
		files/helpers.o					\
		files/sorting.o					\
		actions/push_a.o				\
		actions/push_b.o				\
		actions/rotate_a.o				\
		actions/rotate_b.o				\
		actions/swap_a.o				\
		actions/swap_b.o				\
		actions/reverse_rotate_a.o		\
		actions/reverse_rotate_b.o		\
		files/redacted_stlist.o			\

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	${MAKE} -C ./libft fclean
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re