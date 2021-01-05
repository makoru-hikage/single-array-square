CC=gcc
CFLAGS=-g -Wall -lm
APP=sasquare

all: $(APP)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

sasquare: single_array_square.o main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(APP) *.gch
