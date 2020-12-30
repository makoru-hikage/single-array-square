#include "single_array_square.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Based on 1.1.1
 * 
 * @param square 
 * @param base 
 */
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
 * @brief A simple linear search where the sentinel values are based on 1.3.4
 * 
 * @param needle 
 * @param haystack 
 * @param length 
 * @return int 
 */
int int_in_array(int needle, int* haystack, int base) {
    int found = 0;
    int square_size = base * base;

    for (int head = 0; check_cell_index_validity(*haystack, base); head++){
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
void print_int_square(struct single_array_square *square, int *selected_cell_indices){
    int base = square->base;
    int square_size = square->size;

    // Zero padding is required to maintain the visual evenness of the square
    // when printed to stdout
    int square_size_digits = (square_size == 0) ? 1  : ((int)log10(square_size) + 1);

    for (int i = 1; i <= square->size; i++){
        ((int *)square->cells)[i] = i;
        if (int_in_array(i, selected_cell_indices, base)){
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

/**
 * @brief Select a cell index using a row and a column index. See 1.3.9
 * 
 * @param row_index 
 * @param column_index 
 * @param base 
 * @return int 
 */
int intersection_cell_index (int row_index, int column_index, int base){
    int r = row_index;
    int c = column_index;
    int b = base;

    return c - b + (b*r);
}

/**
 * @brief Select all the cell indices in a row
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int *select_row (int index, int base){
    int *row_cell_indices = (int*) malloc (sizeof(int) * base);
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = intersection_cell_index(index, nth_index, base);
        row_cell_indices[i] = cell_index;
        nth_index++;
    }

    return row_cell_indices;
}

/**
 * @brief Select all the cell indices in a row
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int *select_column (int index, int base){
    int *row_cell_indices = (int*) malloc (sizeof(int) * base);
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = intersection_cell_index(nth_index, index, base);
        row_cell_indices[i] = cell_index;
        nth_index++;
    }

    return row_cell_indices;
}