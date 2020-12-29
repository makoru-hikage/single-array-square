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

struct selected_cells select_all_cells (int square_base);

int int_in_array(int needle, int* haystack, int length);

int check_cell_index_validity(struct single_array_square *square, int cell_index);

int check_row_index_validity (int index, int base);

int check_column_index_validity (int index, int base);

void print_int_square(struct single_array_square *square,struct selected_cells *selected);

#endif