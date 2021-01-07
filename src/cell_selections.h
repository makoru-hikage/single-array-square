#ifndef CELL_SELECTIONS
#define CELL_SELECTIONS

int intersection_cell_index (int row_index, int column_index, int base);

int *select_row (int index, int base);

int *select_column (int index, int base);

int select_corner (int index, int base);

int *select_all_corners (int base);

int* select_corners (int index, int base);

int* select_square_center (int base);

int *select_descending_slant (int base);

int *select_ascending_slant (int base);

int *select_all_slants (int base);

int *select_slants (int index, int base);

#endif // CELL_SELECTIONS
