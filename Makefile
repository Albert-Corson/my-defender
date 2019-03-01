##
## EPITECH PROJECT, 2019
## modsf
## File description:
## Makefile
##

SRC			=	src/main.c								\
				src/menu/menu_scene.c					\
				src/menu/menu_evt.c						\
				src/menu/menu_btn_action.c				\
				src/menu/controls/controls_evt.c		\
				src/menu/controls/controls_scene.c		\
				src/menu/options/options_evt.c			\
				src/menu/options/options_scene.c		\
				src/menu/options/options_btn_action.c	\
				src/pres_screen/pres_scene.c			\
				src/pres_screen/pres_evt.c				\
				src/random_gen.c						\
				src/sound.c								\

OBJ			=	$(SRC:.c=.o)

NAME		=	my_defender

GRAPHICS	=	-l csfml-graphics
WINDOW		=	-l csfml-window
SYSTEM		=	-l csfml-system
AUDIO		=	-l csfml-audio
NETWORK		=	-l csfml-network

LDLIBS		=	-Llib -lmsf -lmy $(GRAPHICS) $(SYSTEM) $(AUDIO) $(WINDOW) -lm
INCLUDE		=	-Iinclude
CFLAGS		=	-Wextra -Wall -g $(INCLUDE) $(LDLIBS)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/msf
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

clean:
	$(MAKE) clean -C lib/my
	$(MAKE) clean -C lib/msf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C lib/my
	$(MAKE) fclean -C lib/msf
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re