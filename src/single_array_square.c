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

    while(check_cell_index_validity(*haystack, base)){
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
            printf ("%*d ", square_size_digits, ((int *)square->cells)[i]);
        } else {
            printf ("%*s ", square_size_digits, "*");
        }

        // The rightmost cells are always the multiples of the base.
        if (((int *)square->cells)[i] % square->base == 0){
            printf("\n");
        }
    }
}

/**
 * @brief Get the median of the base. See 3.1.2
 * 
 * @param base 
 * @return int 
 */
int median_of_the_base (int base){
    return (int) floor((base + 1) / 2);
}

/**
 * @brief Finds the opposite of a number within a given base
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int find_opposite (int index, int base){
    return (base + 1) - index; 
}

/**
 * @brief Find the index of the respective row of a cell. See 1.3.5
 * 
 * @param index cell index
 * @param base 
 * @return int 
 */
int row_index(int index, int base){
    // When the dividend and divisor are both int,
    // it'll result into an int. 
    // The argument for a ceil function must be a double, not an int.
    // For example, ceil(1/5) results to 0 instead of 0.2
    // ceil(0) = 0; ceil(0.2) = 1; We want the latter
    // so... ceil((double)1 / 5). Such is C.
    return (int) ceil( (double)index / (double)base);
}

/**
 * @brief Find the index of the respective column of a cell. See 1.3.6
 * 
 * @param index cell index
 * @param base 
 * @return int 
 */
int column_index(int index, int base){
    return index - base * (int) ceil ((double)index / base) + base;
}

/**
 * @brief Takes the row and column index of a cell and add them.
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int intersection_sum(int index, int base){
    return row_index(index, base) + column_index(index, base);
}

/**
 * @brief Takes the row and column index of a cell then subtract the column index from the row
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int intersection_diff(int index, int base){
    return row_index(index, base) - column_index(index, base);
}

/**
 * @brief Gets the descending slope index of a cell
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int descending_index(int index, int base){
    return base - intersection_diff(index, base);
}

/**
 * @brief Gets the ascending slope index of a cell
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int ascending_index(int index, int base){
    return intersection_sum(index, base) - 1;
}