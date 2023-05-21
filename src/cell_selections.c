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
 * @brief Select all the cells
 * 
 * @param base 
 * @return int* 
 */
int *select_all_cells(int base){
    int square_size = base * base;
    int *all_cells = calloc (square_size + 1, sizeof(int));

    for (int i = 0; i < square_size; i++){
        all_cells[i] = i + 1;
    }

    return all_cells;
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
    return select_descending_slope(base, base);
}

/**
 * @brief Select the cells of the ascending slant. See 3.3.2
 * 
 * @param base 
 * @return int* 
 */
int *select_ascending_slant (int base){
    return select_ascending_slope(base, base);
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

/**
 * @brief Select a descending slope by index
 * 
 * @param index descending slope index
 * @param base 
 * @return int* 
 */
int* select_descending_slope(int index, int base){
    int number_of_cells = desc_slope_cell_count(index, base);
    int *cell_indices = calloc (number_of_cells + 1, sizeof(int));

    int d = index;

    // Find the diametric opposite of the descending index
    int d_reverse = (count_all_slopes(base) + 1) - d;

    // Determines whether the slope starts from column or row index 1
    // If it yields 1, the slope shall start at column 1, if 0, then row 1.
    int descending_slope_type = (int)floor((double)d_reverse/base);

    // May result in either 1 or base;
    int y = (int)pow((double)base, descending_slope_type);

    // Intersection difference derived from diagonal index
    int id = base - d;

    for (int n = 1; n <= number_of_cells; n++){
        int cell_index = n + (base*n) - base + y*abs(id);
        cell_indices[n - 1] = cell_index;
    }

    return cell_indices;
}

/**
 * @brief Select an ascending slope by index
 * 
 * @param index ascending slope index
 * @param base 
 * @return int* 
 */
int* select_ascending_slope(int index, int base){
    int l = asc_slope_cell_count(index, base);
    int *cell_indices = calloc (l + 1, sizeof(int));
    int a = index;

    // Determines whether the slope starts from column index 1 or row index b
    // If it yields 1, the slope shall start at column 1, if 0, then row b.
    int ascending_slope_type = (int)floor((double)a/base);

    // May result in either 1 or base;
    int y = (int)pow((double)base, ascending_slope_type);

    // Intersection difference derived from diagonal index
    int id = base - a;

    for (int n = 1; n <= l; n++){
        int cell_index = base*l + base - base*n - l + n - y*id;
        cell_indices[n - 1] = cell_index;
        printf("n %d; i: %d\n", n, cell_index);
    }

    return cell_indices;
}