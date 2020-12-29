#include "single_array_square.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Based on 1.1.1
 * 
 * @param square 
 * @param base 
 */*/
void initialize_square (struct single_array_square *square, int base){
    int square_size = base * base;
    square->size = square_size;
    square->base = base;
}

/**
 * @brief Based on 1.2.2
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int check_cell_index_validity(int index, int base){
    int square_size = base * base;
    return index >= 1 && index <= square_size;
}

/**
 * @brief Based on 1.3.4
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int check_row_index_validity (int index, int base){
    return index >= 1 && index <= base;
}

/**
 * @brief Based on 1.3.4
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int check_column_index_validity (int index, int base){
    return index >= 1 && index <= base;
}

/**
 * @brief Create a struct that indicates selected cells and its count.
 * 
 * @param square_base 
 * @return struct selected_cells 
 */
struct selected_cells select_all_cells (int square_base){
    struct selected_cells cells;
    int square_size = square_base * square_base;
    cells.indices = (int *) malloc (sizeof(int) * (square_size + 1));
    cells.count = square_size;

    for (int i = 0; i <= square_size; i++){
        cells.indices[i] = i + 1;
    }

    return cells;
}

/**
 * @brief A simple linear search from an array of integers
 * 
 * @param needle 
 * @param haystack 
 * @param length 
 * @return int 
 */
int int_in_array(int needle, int* haystack, int length) {
    int found = 0;

    for (int head = 0; head < length; head++){
        found = (*haystack == needle);
        if (found) 
            break;

        //Continue with the haystack.
        haystack++;
    }

    return found;
}

/**
 * @brief Print a perfect (n x n) square to stdout
 * 
 * @param square 
 * @param selected 
 */
void print_int_square(struct single_array_square *square, struct selected_cells *selected){
    int base = square->base;
    int square_size = square->size;

    // Zero padding is required to maintain the visual evenness of the square
    // when printed to stdout
    int square_size_digits = (square_size == 0) ? 1  : ((int)log10(square_size) + 1);

    for (int i = 1; i <= square->size; i++){
        ((int *)square->cells)[i] = i;
        if (int_in_array(i, selected->indices, selected->count)){
            printf ("%0*d ", square_size_digits, ((int *)square->cells)[i]);
        } else {
            printf ("%0*s ", square_size_digits, "*");
        }

        // The rightmost cells are always the multiples of the base.
        if (((int *)square->cells)[i] % square->base == 0){
            printf("\n");
        }
    }
}