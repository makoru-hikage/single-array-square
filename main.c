#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/single_array_square.h"

void print_help () {
    printf("\n single_array_square <BASE> <COMMAND>\n");
}

int main (int argc, char *argv[]) {

    if (argc < 2){
        print_help();
        return 0;
    }

    int base = atoi(argv[1]);
    printf("\n");

    if (base > 1){

        struct single_array_square square;
        struct selected_cells sc = select_all_cells(base);

        initialize_square(&square, base);
        square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

        print_int_square(&square, &sc);

        free (sc.indices);
        free (square.cells);

        printf("\n");
        return 0;
    }

    printf("Were you inputting non-integers?\n");
    return 0;
}