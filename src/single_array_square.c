#include "single_array_square.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUMBER_OF_CORNERS 4

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
 * @brief Select all the cell indices in a row. See 1.3.7
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int *select_row (int index, int base){
    int *row_cell_indices = calloc (base + 1, sizeof(int));
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = intersection_cell_index(index, nth_index, base);
        row_cell_indices[i] = cell_index;
        nth_index++;
    }

    return row_cell_indices;
}

/**
 * @brief Select all the cell indices in a column. See 1.3.8
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int *select_column (int index, int base){
    int *column_cell_indices = calloc (base + 1, sizeof(int));
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = intersection_cell_index(nth_index, index, base);
        column_cell_indices[i] = cell_index;
        nth_index++;
    }

    return column_cell_indices;
}

/**
 * @brief Select a corner cell of a square. See 2.3
 * 
 * @param index
 * @param base 
 * @return int 
 */
int select_corner (int index, int base){
    int square_size = base * base;

    switch(index){
        case UP_LEFT:
            return 1;
        case UP_RIGHT:
            return base;
        case DOWN_LEFT:
            return square_size - (base - 1);
        case DOWN_RIGHT:
            return square_size;
        default:
            return 0;
    }
}

/**
 * @brief Select all the corner cells of a square. See 2.3
 * 
 * @param base 
 * @return int* 
 */
int* select_all_corners (int base){

    int *selected_cells = calloc (NUMBER_OF_CORNERS + 1, sizeof(int));

    selected_cells[0] = select_corner(UP_LEFT, base);
    selected_cells[1] = select_corner(UP_RIGHT, base);
    selected_cells[2] = select_corner(DOWN_LEFT, base);
    selected_cells[3] = select_corner(DOWN_RIGHT, base);

    return selected_cells;
}

/**
 * @brief Choose either one corner or all corners. See 2.3
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int* select_corners (int index, int base){

    int *selected_cells = calloc (NUMBER_OF_CORNERS + 1, sizeof(int));

    switch(index){
        case UP_LEFT:
        case UP_RIGHT:
        case DOWN_LEFT:
        case DOWN_RIGHT:
            selected_cells[0] = select_corner(index, base);
            break;
        case ALL:
            free(selected_cells);
            return select_all_corners(base);
        default:
            return 0; 
    }

    return selected_cells;
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
 * @brief Get the middle quadrant or cell of the square. See 3.2.2 and 3.2.3
 * 
 * @param base 
 * @return int* 
 */
int* select_square_center (int base){
    int base_is_even = ! (base % 2 != 0);
    int m = median_of_the_base(base);
    int number_of_center_cells = base_is_even ? 4 : 1;

    int* selected_cells = calloc (number_of_center_cells + 1, sizeof(int));

    selected_cells[0] = intersection_cell_index(m,m,base);

    if (base_is_even){
        int first_center_quadrant_index = selected_cells[0];

        // second_center_quadrant_index
        selected_cells[1] = first_center_quadrant_index + 1;
        // third_center_quadrant_index
        selected_cells[2] = first_center_quadrant_index + base;
        // fourth_center_quadrant_index
        selected_cells[3] = first_center_quadrant_index + base + 1;
    }

    return selected_cells;
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
 * @brief Select the cells of the descending slant. See 3.3.1
 * 
 * @param base 
 * @return int* 
 */
int *select_descending_slant (int base){
    int *cell_indices = calloc (base + 1, sizeof(int));
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = intersection_cell_index(nth_index, nth_index, base);
        cell_indices[i] = cell_index;
        nth_index++;
    }

    return cell_indices;
}

/**
 * @brief Select the cells of the ascending slant. See 3.3.2
 * 
 * @param base 
 * @return int* 
 */
int *select_ascending_slant (int base){
    int *cell_indices = calloc (base + 1, sizeof(int));
    int nth_index = 1;

    for (int i = 0; i < base; i++){
        int cell_index = (base*nth_index) - (nth_index - 1);
        cell_indices[i] = cell_index;
        nth_index++;
    }

    return cell_indices;
}

/**
 * @brief Select all the slants (forms a diagonal cross.)
 * 
 * @param base 
 * @return int* 
 */
int *select_all_slants (int base){
    //number of cells from two slants combined
    int number_of_cells = base * 2;

    int *cell_indices = calloc (number_of_cells + 1, sizeof(int));
    int nth_index = 1;

    // `di` denotes the indices of the descending slant
    // `ai` denotes the indices of the ascending slant
    for (int di = 0, ai = number_of_cells - 1; di < base, ai >= base; di++, ai--){

        // The formula of the descending slant
        int cell_index = intersection_cell_index(nth_index, nth_index, base);
        // Pertains to the opposite cell in a column. TODO: Docs elaborating on opposite cells.
        int opposite_cell_index = intersection_cell_index(nth_index, find_opposite(nth_index, base), base);

        cell_indices[di] = cell_index;
        cell_indices[ai] = opposite_cell_index;
        nth_index++;
    }

    return cell_indices;

}

/**
 * @brief Select one or two slants
 * 
 * @param index 
 * @param base 
 * @return int* 
 */
int *select_slants (int index, int base){
    switch(index){
        case UP_RIGHT:
        case DOWN_LEFT:
            return select_ascending_slant(base);
        case UP_LEFT:
        case DOWN_RIGHT:
            return select_descending_slant(base);
        default:
            return select_all_slants(base);
    }
}