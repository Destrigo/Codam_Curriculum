CC = cc
HEADER = pipex.h
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = pipex
OBJS =  src/main.o					\
		src/childs.o				\
		src/helpers.o				\
		src/parcing.o				\

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