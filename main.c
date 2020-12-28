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
    struct selected_cells sc = select_all_cells(base);

    initialize_square(&square, base);
    square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

    print_int_square(&square, &sc);

    free (sc.indices);
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