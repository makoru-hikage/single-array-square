#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "src/single_array_square.h"

typedef int * (*select_line_function) (int, int);

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

void print_selected_line(int index, int base, select_line_function select_line){
    int* selected_cells = select_line(index, base);
    print_square(base, selected_cells);

    free (selected_cells);
}

int main (int argc, char *argv[]) {

    int opt = 0;
    int base = 0;
    int all_cells_are_selected = 1;

    if (optind < argc){
        base = atoi(argv[optind]);
        printf("\n");
    } else {
        print_help();
        return 0;
    }

    while((opt = getopt(argc, argv, "ac:d:j:mr:")) != -1){
        switch(opt){
            case 'a': {
                all_cells_are_selected = 0;
                print_full_square(base);
                break;
            }

            case 'r': {
                all_cells_are_selected = 0;
                int row_index = atoi(optarg);
                print_selected_line(row_index, base, select_row);
                break;
            }

            case 'c': {
                all_cells_are_selected = 0;
                int column_index = atoi(optarg);
                print_selected_line(column_index, base, select_column);

                break;
            }

            case 'j': {
                all_cells_are_selected = 0;
                int index = atoi(optarg);
                int* selected_cells = select_corners(index, base);

                print_square(base, selected_cells);

                break;
            }

            case 'm': {
                all_cells_are_selected = 0;
                int* selected_cells = select_square_center(base);

                print_square(base, selected_cells);

                break;
            }

            case 'd': {
                all_cells_are_selected = 0;
                int index = atoi(optarg);
                int* selected_cells = select_slants(index, base);

                print_square(base, selected_cells);

                break;
            }

            default: {
                print_help();
                return 0;
            }
        }
    }

    if (all_cells_are_selected){
        print_full_square(base);
    }

    return 0;
}