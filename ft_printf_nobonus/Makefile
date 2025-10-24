PROJECT = printf
CC = cc
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libftprintf.a
OBJS =  ft_printf_c.o		\
		ft_printf_d.o		\
		ft_printf_i.o		\
		ft_printf_lowx.o	\
		ft_printf_p.o		\
		ft_printf_s.o		\
		ft_printf_u.o		\
		ft_printf_upx.o		\
		ft_printf.o	
	
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: