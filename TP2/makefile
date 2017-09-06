SHELL=/bin/bash

.SUFFIXES : .o .cpp

EXE = ratio
SRC = ratio.cpp gcd.cpp rational.cpp
OBJ = $(SRC:.cpp=.o)

$(EXE): $(OBJ)
	g++ -o $@ -Wall $(OBJ) -lstdc++ -lm

.cpp.o:
	g++ -c -Wall -g -I/usr/include/g++  $<

clean:
	rm -rf *.o
	rm -rf $(EXE)
