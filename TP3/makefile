SHELL=/bin/bash

.SUFFIXES : .o .cpp

EXE = principal
SRC = principal.cpp tab.cpp tab_math.cpp 
OBJ = $(SRC:.cpp=.o)

$(EXE): $(OBJ)
	g++ -o $@ -Wall -g $(OBJ) -lm

.cpp.o:
	g++ -c -Wall -g $<



