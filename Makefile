##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = my_runner

CC    = gcc

RM    = rm -f

SRC    = myrunner.c				\

OBJ    = $(SRC:.c=.o)

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME):
	cd ./lib/my/ && make
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all
