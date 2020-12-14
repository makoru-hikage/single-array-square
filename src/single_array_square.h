#ifndef SINGLE_ARRAY_SQUARE
#define SINGLE_ARRAY_SQUARE

struct single_array_square{
    int base;
    int size;
    int index: 1;
    void* cells;
};

void initialize_square (struct single_array_square *square, int base);

int check_cell_index_validity(struct single_array_square *square, int cell_index);

#endif