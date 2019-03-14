##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## Makefile
##

SRC			=	src/main.c									\
				src/load_sound.c							\
				src/tools/create_scenes.c					\
				src/tools/create_anim_obj.c					\
				src/tools/random_gen.c						\
				src/tools/sound.c							\
				src/tools/create_btn.c						\
				src/tools/create_defense.c					\
				src/tools/get_focused_btn.c					\
				src/tools/is_tile_available.c				\
				src/menu/menu_scene.c						\
				src/menu/menu_evt.c							\
				src/menu/menu_btn_action.c					\
				src/menu/options/options_evt.c				\
				src/menu/options/options_scene.c			\
				src/menu/options/options_btn_action.c		\
				src/pres_screen/pres_scene.c				\
				src/pres_screen/pres_evt.c					\
				src/game/game_scene.c						\
				src/game/game_btn_action.c					\
				src/game/game_evt.c							\
				src/game/game_place_defense.c				\
				src/game/create_objs/game_create_hud.c		\
				src/game/create_objs/game_create_sound.c	\
				src/game/create_objs/game_create_emp.c		\
				src/game/pause/pause_btn_action.c			\
				src/game/pause/pause_evt.c					\
				src/game/pause/pause_scene.c				\
				src/defense/defense_get.c					\
				src/defense/defense_set.c					\
				src/defense/defense_met.c					\
				src/defense/defense_vtable.c				\
				src/defense/defense_tor.c					\
				src/defense/defense_evts.c					\
				src/enemy/enemy_tor.c						\
				src/enemy/enemy_evts.c						\
				src/test/missile/missile_tor.c				\
				src/test/missile/missile_evts.c				\
				src/test/test_scene.c						\
				src/parsing/checks.c						\
				src/parsing/parser.c						\
				src/parsing/textures.c						\
				src/parsing/pathfinding/check_path.c

OBJ			=	$(patsubst %.c,%.o,$(SRC))

DEPS		=	lib/my									\
				lib/msf

NAME		=	my_defender

CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio
LDLIBS		=	-Llib -lmsf -lmy $(CSFML) -lm
INCLUDE		=	-Iinclude
CFLAGS		=	-Wextra -Wall -g $(INCLUDE) $(LDLIBS)

all:
	uptodate=0;\
	if [ -f $(NAME) ];then\
		uptodate=1;\
		for file in $(SRC);do\
			if [[ ! -f $${file//.c/.o} ]];then\
				uptodate=0;\
			fi;\
			if [[ -n "$$(find . -regex \.?\/?$$file -a -newer $(NAME))" ]];then\
				uptodate=0;\
			fi;\
		done;\
	fi;\
	if [ $$uptodate == 1 ];then\
		echo "make: '$(NAME)' is up to date.";\
	else\
		rm -f $(NAME);\
		make $(NAME);\
	fi;

$(NAME):
	for dep in $(DEPS);do\
		$(call TERMLOG,$(INFO),[ENTERING DEPENDENCY DIRECTORY '$$dep']:);\
		make -C $$dep;\
		$(call TERMLOG,$(INFO),[LEAVING DEPENDENCY DIRECTORY '$$dep']\n);\
	done;\
	status=1;\
	$(call TERMLOG,$(HEADER),BUILDING SOURCES : ,$(INFO),[$(CFLAGS)]);\
	for file in $(SRC);do\
		if [ ! -f $$file ];then\
			$(call TERMLOG,$(NORMAL),'$$file' is missing. ,$(ERROR),[NO FILE]);\
			status=0;\
			break;\
		else\
			cc -o $${file//.c/.o} -c $$file $(CFLAGS);\
			if [[ "$$?" == 0 ]];then\
				$(call TERMLOG,$(NORMAL),building '$$file' ,$(SUCCESS),[OK]);\
			else\
				status=0;\
				$(call TERMLOG,$(NORMAL),building '$$file' ,$(ERROR),[KO]);\
			fi;\
		fi;\
	done;\
	if [ "$$status" == 1 ];then\
		$(call TERMLOG,$(HEADER),\nLINKING OBJECTS : );\
		cc -o $(NAME) $(OBJ) $(CFLAGS);\
		if [[ "$$?" == 0 ]];then\
			$(call TERMLOG,$(NORMAL),linking '$(NAME)' ,$(SUCCESS),[OK]);\
		else\
			$(call TERMLOG,$(NORMAL),linking '$(NAME)' ,$(ERROR),[KO]);\
		fi;\
	fi;

clean:
	for dep in $(DEPS);do\
		$(call TERMLOG,$(INFO),[ENTERING DEPENDENCY DIRECTORY '$$dep']:);\
		make $@ -C $$dep;\
		$(call TERMLOG,$(INFO),[LEAVING DEPENDENCY DIRECTORY '$$dep']\n);\
	done;\
	$(call TERMLOG,$(HEADER),DELETING OBJECTS : );\
	for obj in $(OBJ);do\
		rm -f $$obj;\
		if [ "$$?" == 0 ];then\
			$(call TERMLOG,$(NORMAL),removing '$$obj' ,$(SUCCESS),[OK]);\
		else\
			$(call TERMLOG,$(NORMAL),removing '$$obj' ,$(ERROR),[KO]);\
		fi;\
	done;

fclean:	clean
	printf "\n";
	for dep in $(DEPS);do\
		$(call TERMLOG,$(INFO),[ENTERING DEPENDENCY DIRECTORY '$$dep']:);\
		make $@ -C $$dep;\
		$(call TERMLOG,$(INFO),[LEAVING DEPENDENCY DIRECTORY '$$dep']\n);\
	done;\
	$(call TERMLOG,$(HEADER),DELETING TARGET : );\
	rm -f $(NAME);\
	if [ "$$?" == 0 ];then\
		$(call TERMLOG,$(NORMAL),removing '$(NAME)' ,$(SUCCESS),[OK]);\
	else\
		$(call TERMLOG,$(NORMAL),removing '$(NAME)' ,$(ERROR),[KO]);\
	fi;

re:	fclean all

.PHONY:	all clean fclean re

ifndef VERBOSE
.SILENT:
endif

define GET_PADDING
	$$(($$(tput cols) - $$(expr length "$1") + 1))
endef
define TERMLOG
	printf "$1%b$(NORMAL)$3%*b$(NORMAL)" "$2" $(call GET_PADDING,$2) "$4\n"
endef

NORMAL	=	\e[39m\e[0m
HEADER	=	\e[39m\e[1m
DEP		=	\e[94m\e[1m
INFO	=	\e[93m
ERROR	=	\e[31m\e[1m
SUCCESS	=	\e[92m