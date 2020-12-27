#include "single_array_square.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void initialize_square (struct single_array_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
}

int check_cell_index_validity(struct single_array_square *square, int cell_index) {
    int square_size = square->size;
    return cell_index >= 1 && cell_index <= square_size;
}

void print_int_square(struct single_array_square *square){
    int base = square->base;
    int square_size = square->size;

    // Zero padding is required to maintain the visual evenness of the square
    // when printed to stdout
    int square_size_digits = (square_size == 0) ? 1  : ((int)log10(square_size) + 1);

    for (int i = 1; i <= square->size; i++){
        ((int *)square->cells)[i] = i;
        printf ("%0*d ", square_size_digits, ((int *)square->cells)[i]);

        // The rightmost cells are always the multiples of the base.
        if (((int *)square->cells)[i] % square->base == 0){
            printf("\n");
        }
    }
}