#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "single_array_square.h"
#include "cell_selections.h"

typedef int * (*select_line_function) (int, int);

void print_help (char* program_name) {

    printf("USAGE: %s BASE [OPTIONS]...\n\n", program_name);
    puts(
        "Print a perfect square with a BASE of a chosen integer.\n"
        "Selects all the cells when options aren't specified.\n"
        "\n"
        "OPTIONS:\n"
        "  -a                select all cells\n"
        "  -c INDEX          select all cells within a column by column INDEX\n"
        "  -d DIRECTION      select a particular slant:\n"
        "                      5 or 6 for the descending slant\n"
        "                      4 or 7 for the ascending slant\n"
        "                      other integers to select all indices of all slants\n"
        "  -j INDEX          select a particular corner:\n"
        "                      4 for the top-left corner\n"
        "                      5 for the top-right corner\n"
        "                      6 for the down-left corner\n"
        "                      7 for the down-right corner\n"
        "                      8 for all corners\n"
        "                      others select none.\n"
        "  -m                select the central part of a square\n"
        "  -r INDEX          select all cells within a row by row INDEX\n"
    );

}

void print_square(int base, int *selected_cell_indices){
    struct single_array_square square;

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
        if (base <= 0){
            printf ("ERROR: Please supply only non-zero positive integers before specifying any options.\n\n");
            print_help(argv[0]);
            return 1;
        }
    } else {
        print_help(argv[0]);
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

                free (selected_cells);
                break;
            }

            case 'm': {
                all_cells_are_selected = 0;
                int* selected_cells = select_square_center(base);

                print_square(base, selected_cells);

                free (selected_cells);
                break;
            }

            case 'd': {
                all_cells_are_selected = 0;
                int index = atoi(optarg);
                int* selected_cells = select_slants(index, base);

                print_square(base, selected_cells);

                free (selected_cells);
                break;
            }

            default: {
                print_help(argv[0]);
                return 0;
            }
        }
    }

    if (all_cells_are_selected){
        print_full_square(base);
    }

    return 0;
}