NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c path_utils.c utils_1.c utils_2.c

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f pipex

re : fclean all

.PHONY : all clean fclean re
