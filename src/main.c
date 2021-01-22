#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include "single_array_square.h"
#include "cell_selections.h"
#include "symmetry.h"

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

void exit_on_input_error(){
    fprintf(stderr, "Please input an integer as an argument.\n\n");
    exit(EXIT_FAILURE);
}

void exit_on_error () {
    perror("ERROR");
    exit(EXIT_FAILURE);
}

void print_square(int base, int *selected_cell_indices){
    struct single_array_square square;

    initialize_square(&square, base);
    square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

    print_int_square(&square, selected_cell_indices);

    free (square.cells);

    printf("\n");
}

void print_selected_cells(int base, int* selected_cells){
    print_square(base, selected_cells);
    free (selected_cells);
}

int main (int argc, char *argv[]) {

    int opt = 0;
    int base = 0;
    int long_index = 0;
    int* selected_cells = NULL;
    char* endptr; //used by strtol to store memory addresses of erratic characters.

    static struct option long_options[] = {
        {"all", no_argument, 0, 'a'},
        {"row", required_argument, 0, 'r'},
        {"column", required_argument, 0, 'c'},
        {"slant", required_argument, 0, 'd'},
        {"corner", required_argument, 0, 'j'},
        {"center", no_argument, 0, 'm'},
        {0,0,0,0}
    };

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

    while((opt = getopt_long(argc, argv, "ac:d:j:mr:", long_options, &long_index)) != -1){
        switch(opt){
            case 'a': {
                if (selected_cells == NULL)
                    selected_cells = select_all_cells(base);
                break;
            }

            case 'r': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);

                    if (*endptr != '\0')
                        exit_on_input_error();

                    if (errno != 0)
                        exit_on_error();

                    selected_cells = select_row(index, base);
                }
                break;
            }

            case 'c': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);

                    if (*endptr != '\0')
                        exit_on_input_error();

                    if (errno != 0)
                        exit_on_error();

                    selected_cells = select_column(index, base);
                }
                break;
            }

            case 'j': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);

                    if (*endptr != '\0')
                        exit_on_input_error();

                    if (errno != 0)
                        exit_on_error();

                    selected_cells = select_corners(index, base);
                }

                break;
            }

            case 'm': {
                if (selected_cells == NULL)
                    selected_cells = select_square_center(base);
                break;
            }

            case 'd': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);

                    if (*endptr != '\0')
                        exit_on_input_error();

                    if (errno != 0)
                        exit_on_error();

                    selected_cells = select_slants(index, base);
                }

                break;
            }

            default: {
                print_help(argv[0]);
                return 0;
            }
        }
    }

    if (selected_cells == NULL){
        selected_cells = select_all_cells(base);
    }

    print_selected_cells(base, selected_cells);

    return 0;
}