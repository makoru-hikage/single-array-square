CC=gcc
CFLAGS=-g -Wall -lm -std=c11
APP=sasquare

all: $(APP)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

sasquare: single_array_square.o cell_selections.o symmetry.o main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(APP) *.gch
