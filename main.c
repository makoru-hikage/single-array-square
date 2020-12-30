#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "src/single_array_square.h"

void print_help () {
    printf("\n USAGE: single_array_square <BASE>\n\n");
}

void print_full_square(int base){
    struct single_array_square square;
    int square_size = base * base;
    int selected_cell_indices[square_size];

    for (int i = 0; i < square_size; i++) selected_cell_indices[i] = i + 1;

    initialize_square(&square, base);
    square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

    print_int_square(&square, selected_cell_indices);

    free (square.cells);

    printf("\n");
}

int main (int argc, char *argv[]) {

    int opt;

    if (optind < argc){
        int base = atoi(argv[optind]);
        printf("\n");

        if (base > 0){
            print_full_square(base);
            return 0;
        }

        print_help();
        return 0;
    }

    while((opt = getopt(argc, argv, "r:c:")) != -1)  
    {
        switch(opt)
        {
            case 'r':
                // TODO: Select cells by row index
                break;

            case 'c':
                // TODO: Select cells by column index
                break;

            default:
                print_help();
        }
    }

    return 0;
}