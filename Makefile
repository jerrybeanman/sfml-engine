
CC				= 		g++
NAME			=		engine
FLAGS			= 		-std=c++11 -Wall 
LIBRARIES		= 		-lsfml-graphics -lsfml-window -lsfml-system
S_FILES			= 		main.cpp Game.cpp 
OBJECT_FILES	=		$(S_FILES:.cpp=.o)
META_FILES		=		$(S_FILES:.cpp=.cpp.meta)


all:
			$(CC) $(FLAGS) -o $(NAME) $(S_FILES) $(LIBRARIES)

debug:
			$(CC) $(FLAGS) -ggdb -o $(NAME) $(S_FILES) $(LIBRARIES)

clean:
			rm $(OBJECT_FILES) $(NAME) 

remake:
			make clean
			clear
			make
