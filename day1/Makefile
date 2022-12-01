SRCS = calories.c
OBJS = $(SRCS:.c=.o)
NAME = calories
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./../libft/
LIBFT = $(LIBFT_PATH)libft.a

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(OBJS) $(LIBFT) -o $(NAME)

			
$(LIBFT):
				git submodule update --init
				make all -C $(LIBFT_PATH)

clean:	
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)


fclean:	clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re