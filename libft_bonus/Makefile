PROJECT = libft
CC = cc
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libft.a
OBJS =  ft_split.o 			\
		ft_itoa.o 			\
		ft_strmapi.o 		\
		ft_striteri.o 		\
		ft_strtrim.o		\
		ft_strjoin.o 		\
		ft_substr.o 		\
		ft_putnbr_fd.o 		\
		ft_putendl_fd.o 	\
		ft_putstr_fd.o 		\
		ft_putchar_fd.o 	\
		ft_strdup.o		 	\
		ft_calloc.o 		\
		ft_strnstr.o 		\
		ft_strlcat.o 		\
		ft_memcmp.o 		\
		ft_atoi.o 			\
		ft_strnstr.o 		\
		ft_memchr.o 		\
		ft_memset.o 		\
		ft_memcpy.o 		\
		ft_memmove.o 		\
		ft_strlcat.o 		\
		ft_strlcpy.o 		\
		ft_bzero.o 			\
		ft_isalpha.o 		\
		ft_toupper.o 		\
		ft_isdigit.o 		\
		ft_tolower.o 		\
		ft_isalnum.o 		\
		ft_strchr.o 		\
		ft_isascii.o 		\
		ft_isprint.o 		\
		ft_strrchr.o 		\
		ft_strlen.o 		\
		ft_strncmp.o
BONUS_OBJS = ft_lstnew_bonus.o 		\
		ft_lstadd_front_bonus.o 	\
		ft_lstsize_bonus.o 			\
		ft_lstlast_bonus.o 			\
		ft_lstadd_back_bonus.o 		\
		ft_lstdelone_bonus.o 		\
		ft_lstclear_bonus.o 		\
		ft_lstiter_bonus.o 			\
		ft_lstmap_bonus.o

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus