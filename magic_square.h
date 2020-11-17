#ifndef MAGIC_SQUARE
#define MAGIC_SQUARE

struct int_magic_square{
    int base;
    int size;
    int index: 1;
    int* cells;
};

struct char_magic_square{
    int base;
    int size;
    int index: 1;
    char* cells;
};

void initialize_int_square (struct int_magic_square *square, int base);

void initialize_char_square (struct char_magic_square *square, int base);

#endif