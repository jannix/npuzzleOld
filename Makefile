NAME =	id_npuzzle
LIBRARY_NAME = ID_glibrary.a
SRC = \
      	main.cpp\
	UI_Panel.cpp\
	UI_Start.cpp\
	UI_LoadImage.cpp\
	UI_SelectSize.cpp\
	UI_PlayBoard.cpp\
	AI_Solver.cpp


LDFLAGS	+= -lpthread -lSDL -lSDL_ttf -lefence
CXXFLAGS+= -Wall -W -Werror -lpthread -lSDL -lSDL_ttf -lefence -D__SDL -g3
OBJ	= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	clang++ -o ${NAME} ${OBJ} ${LIBRARY_NAME} ${CXXFLAGS}

clean:
	rm -f ${OBJ}

distclean: clean
	rm -rf $(NAME)

rebuild: distclean $(NAME)

getfilename:
	find . -name "*.c" | sed "s/\.\///" | sed "s/\.c/.c\\\/"

debug1:	CXXFLAGS += -D__DEBUG
debug1:	debug

debug2:	LDFLAGS += -lefence
debug2:	debug1

debug3:	CXXFLAGS += -pg
debug3:	LDFLAGS += -pg
debug3:	debug2

