CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -lm
DEP=graph.h listGraph.h estudo2.c
OBJ=graph.o listGraph.o estudo2.o
DEP2=graph.h matrixGraph.h estudo.c
OBJ2=graph.o matrixGraph.o estudo.o
EXECUTABLE=teste

all: $(OBJ) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS)

%.o: %.c $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(EXECUTABLE)

