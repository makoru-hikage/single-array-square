#ifndef SINGLE_ARRAY_SQUARE
#define SINGLE_ARRAY_SQUARE

#define NUMBER_OF_CORNERS 4

enum direction {
    UP,             //0b0000
    DOWN,           //0b0001
    LEFT,           //0b0010
    RIGHT,          //0b0011
    UP_LEFT,        //0b0100
    UP_RIGHT,       //0b0101
    DOWN_LEFT,      //0b0110
    DOWN_RIGHT,     //0b0111
    ALL             //0b1000
};

struct single_array_square{
    int base;
    int size;
    int index: 1;
    void* cells;
};


void initialize_square (struct single_array_square *square, int base);

int int_in_array(int needle, int* haystack, int base);

int check_cell_index_validity(int index, int base);

int check_row_index_validity (int index, int base);

int check_column_index_validity (int index, int base);

void print_int_square(struct single_array_square *square, int *selected_cell_indices);

int intersection_cell_index (int row_index, int column_index, int base);

int median_of_the_base (int base);

int find_opposite (int index, int base);

int row_index(int index, int base);

int column_index(int index, int base);

int intersection_sum(int index, int base);

int intersection_diff(int index, int base);

int descending_index(int index, int base);

int ascending_index(int index, int base);

#endif //SINGLE_ARRAY_SQUARE