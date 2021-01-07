#include "cell_selections.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "single_array_square.h"

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
            selected_cells[0] = 0; 
    }

    return selected_cells;
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
    for (int di = 0, ai = number_of_cells - 1; di < base; di++, ai--){

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