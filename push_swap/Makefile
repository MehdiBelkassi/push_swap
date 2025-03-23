SRC = operations.c push_swap.c the_split.c utils.c parsing.c sort.c\
	range.c\

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