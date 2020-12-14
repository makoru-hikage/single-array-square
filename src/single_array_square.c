#include<stdlib.h>
#include "single_array_square.h"

void initialize_square (struct single_array_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
}

int check_cell_index_validity(struct single_array_square *square, int cell_index) {
    int square_size = square->size;
    return cell_index >= 1 && cell_index <= square_size;
}
