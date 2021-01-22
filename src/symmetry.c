#include "symmetry.h"

#include "single_array_square.h"

/**
 * @brief Find a cell's opposite along a row
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int horizontal_opposite (int index, int base){
    int r = row_index(index, base);
    int c = column_index(index, base);
    int opposite_c = find_opposite(c, base);

    return intersection_cell_index(r, opposite_c, base);
}

/**
 * @brief Find a cell's opposite along a column
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int vertical_opposite (int index, int base){
    int r = row_index(index, base);
    int c = column_index(index, base);
    int opposite_r = find_opposite(r, base);

    return intersection_cell_index(opposite_r, c, base);
}

/**
 * @brief Find a cell's opposite along a descending slope
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int descending_opposite (int index, int base){
    // row and column index of the chosen cell
    int r_n = row_index(index, base);
    int c_n = column_index(index, base);
 
    int opposite_r = find_opposite(r_n, base);
    int opposite_c = find_opposite(c_n, base);

    // Intersection sum of opposite cell.
    int is_o = opposite_r + opposite_c;
    // Row index of the opposite cell
    int r_o = is_o - opposite_r;
    // Column index of the opposite cell
    int c_o = is_o - opposite_c;

    return intersection_cell_index(r_o, c_o, base);
}

/**
 * @brief Find a cell's opposite along an ascending slope
 * 
 * @param index 
 * @param base 
 * @return int 
 */
int ascending_opposite (int index, int base){
    // row and column index of the chosen cell
    int r_n = row_index(index, base);
    int c_n = column_index(index, base);
 
    // Intersection sum of chosen cell.
    int is_n = r_n + c_n;
    // Row index of the opposite cell
    int r_o = is_n - r_n;
    // Column index of the opposite cell
    int c_o = is_n - c_n;

    return intersection_cell_index(r_o, c_o, base);
}