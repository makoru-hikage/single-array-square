#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "src/single_array_square.h"

void print_help () {
    printf("\n USAGE: single_array_square <BASE>\n\n");
}

void print_square(int base, int *selected_cell_indices){
    struct single_array_square square;
    int square_size = base * base;

    initialize_square(&square, base);
    square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

    print_int_square(&square, selected_cell_indices);

    free (square.cells);

    printf("\n");
}

void print_full_square(int base){
    int square_size = base * base;
    int all_cells[square_size];

    for (int i = 0; i < square_size; i++){
        all_cells[i] = i + 1;
    }
    print_square(base, all_cells);
}

int main (int argc, char *argv[]) {

    int opt = 0;
    int base = 0;
    int all_selected = 1;

    if (optind < argc){
        base = atoi(argv[optind]);
        printf("\n");
    } else {
        print_help();
        return 0;
    }

    while((opt = getopt(argc, argv, "r:c:i:")) != -1){
        switch(opt){
            case 'r': {
                all_selected = 0;
                int row_index = atoi(optarg);
                int* selected_cells = select_row(row_index, base);
                print_square(base, selected_cells);

                free (selected_cells);
                break;
            }

            case 'c': {
                all_selected = 0;
                int column_index = atoi(optarg);
                int* selected_cells = select_column(column_index, base);
                print_square(base, selected_cells);

                free (selected_cells);
                break;
            }

            default:
                print_help();
        }
    }

    if (all_selected == 1){
        print_full_square(base);
    }

    return 0;
}