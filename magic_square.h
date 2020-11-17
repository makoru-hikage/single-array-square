#ifndef MAGIC_SQUARE
#define MAGIC_SQUARE

struct magic_square{
    int base;
    int size;
    int index: 1;
    void* cells;
};

void initialize_square (struct magic_square *square, int base);

#endif