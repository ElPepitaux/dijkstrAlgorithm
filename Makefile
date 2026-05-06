##
## ELPEPITAUX PROJECT, 2026
## Dijkstra
## File description:
## Makefile
##

SRC	=	$(wildcard sources/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	dijkstra

CFLAGS	=	-Wall -Wextra -Werror -I headers/ -lcsfml-graphics -lcsfml-window -lcsfml-system

CC	=	gcc

all:	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY: all clean fclean re