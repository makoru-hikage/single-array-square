#include<stdlib.h>
#include "single_array_square.h"

void initialize_square (struct single_array_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
}

