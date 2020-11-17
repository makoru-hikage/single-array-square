#include<stdlib.h>
#include "magic_square.h"

void initialize_int_square (struct magic_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
    square->cells = (int *)malloc(sizeof(struct magic_square) + square_size*sizeof(int *));
}

void initialize_char_square (struct magic_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
    square->cells = (char *)malloc(sizeof(struct magic_square) + square_size*sizeof(char *));
}

