SHELL=/bin/sh

.SUFFIXES : .o .cpp

EXE = ppl
SRC = ppl.cpp tab.cpp tab_math.cpp matrice.cpp
OBJ = $(SRC:.cpp=.o)

$(EXE): $(OBJ)
	g++ -o $@ -Wall -Wextra -Werror -g $(OBJ) -llapack -lblas -lgfortran -lm

.cpp.o:
	g++ -c -Wall -Wextra -Werror -g -I/usr/include/g++  $<

clean:
	rm *.o
