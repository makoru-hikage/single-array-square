#include<stdio.h>
#include<stdlib.h>
#include "magic_square.h"

int main (int argc, char *argv[]) {
    int b = 5;
    struct int_magic_square sq;

    initialize_int_square(&sq, b);

    for (int i = 1; i <= sq.size; i++){
        sq.cells[i] = i;
        printf("%d ", sq.cells[i]);
    }

    free(sq.cells);

    return 0;
}