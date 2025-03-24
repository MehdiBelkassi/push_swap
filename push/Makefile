SRC = operations1.c push_swap.c the_split.c utils.c parsing.c sort.c\
	range.c operations2.c operations3.c\

OBJ = $(SRC:.c=.o)

CC = CC
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap



all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	

%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all