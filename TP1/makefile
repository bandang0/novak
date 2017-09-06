SHELL=/bin/bash

.SUFFIXES : .o .cpp

EXE = nom_programme
SRC = nom_ficher1.cpp nom_fichier2.cpp
OBJ = $(SRC:.cpp=.o)

$(EXE): $(OBJ)
	g++ -o $@ -Wall $(OBJ) -lstdc++ -lm

.cpp.o:
	g++ -c -Wall -g -I/usr/include/g++  $<
