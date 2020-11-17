#include<stdlib.h>
#include "magic_square.h"

void initialize_square (struct magic_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
}

