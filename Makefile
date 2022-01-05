##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = my_runner

CC    = gcc

RM    = rm -f

SRC    = main.c								\
		 src/create_sprite.c				\
		 src/display.c						\
		 src/myrunner.c						\
		 src/move_rect.c					\
		 src/game.c							\
		 src/gamepause.c					\
		 src/gamemenu.c						\
		 src/gameover.c						\
		 src/gamewin.c						\
		 src/init_struct.c					\
		 src/destroy_variables.c			\
		 src/create_obstacles.c				\
		 src/create_sprite_obstacles.c 		\
		 src/display_obstacles.c			\
		 src/detect_obstacles.c				\
		 src/display_score.c				\
		 src/destroy_sprite.c				\
		 src/check_obstacles.c				\

OBJ    = $(SRC:.c=.o)

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics -lcsfml-window \
-lcsfml-system -lcsfml-audio													\

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
