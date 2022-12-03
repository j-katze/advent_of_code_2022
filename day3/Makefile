SRCS = rucksack.c
OBJS = $(SRCS:.c=.o)
SRCS2 = badges.c
OBJS2 = $(SRCS2:.c=.o)
NAME = rucksack
NAME2 = badges
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./../libft/
LIBFT = $(LIBFT_PATH)libft.a

all:	$(LIBFT) $(NAME) $(NAME2)

$(NAME):	$(OBJS)
				$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME2):	$(OBJS2)
				$(CC) $(OBJS2) $(LIBFT) -o $(NAME2)

			
$(LIBFT):
				git submodule update --init
				make all -C $(LIBFT_PATH)

clean:	
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJS) $(OBJS2)


fclean:	clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME) $(NAME2)

re:	fclean all

.PHONY:	all clean fclean re