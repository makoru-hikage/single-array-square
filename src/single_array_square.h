#ifndef SINGLE_ARRAY_SQUARE
#define SINGLE_ARRAY_SQUARE

struct single_array_square{
    int base;
    int size;
    int index: 1;
    void* cells;
};

struct selected_cells{
    int* indices;
    int count;
};

void initialize_square (struct single_array_square *square, int base);

int int_in_array(int needle, int* haystack, int base);

int check_cell_index_validity(int index, int base);

int check_row_index_validity (int index, int base);

int check_column_index_validity (int index, int base);

void print_int_square(struct single_array_square *square, int *selected_cell_indices);

int intersection_cell_index (int row_index, int column_index, int base);

int *select_row (int index, int base);

#endif