#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>

#include "single_array_square.h"
#include "cell_selections.h"
#include "symmetry.h"

#define PROGRAM_NAME argv[0] 

void print_help (char* program_name) {

    printf("USAGE: %s BASE [OPTIONS]...\n\n", program_name);
    puts(
        "Print a perfect square with a BASE of a chosen integer.\n"
        "Selects all the cells when options aren't specified.\n"
        "\n"
        "OPTIONS:\n"
        "  -a, --ascending-slope=INDEX          select all cells in an ascending slope\n"
        "  -A, --ascending-opposite=INDEX       select a cell and its opposite along an ascending slant\n"
        "  -c, --column=INDEX                   select all cells within a column by column INDEX\n"
        "  -C, --vertical-opposite=INDEX        select a cell and its opposite along a column\n"
        "  -d, --descending-slope=INDEX         select all cells in a descending slope\n"
        "  -D, --descending-opposite=INDEX      select a cell and its opposite along an descending slant\n"
        "  -j, --corner=INDEX                   select a particular corner:\n"
        "                                           4 for the top-left corner\n"
        "                                           5 for the top-right corner\n"
        "                                           6 for the down-left corner\n"
        "                                           7 for the down-right corner\n"
        "                                           8 for all corners\n"
        "                                           others select none.\n"
        "  -m, --center                         select the central part of a square\n"
        "  -r, --row=INDEX                      select all cells within a row by row INDEX\n"
        "  -R, --horizontal-opposite=INDEX      select a cell and its opposite along a row\n"
        "  -x, --cross                          select the longest two slopes\n"
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

void exit_on_row_index_error (int base) {
    fprintf(stderr, "Row index must be between 1 and %d.\n\n", base);
    exit(EXIT_FAILURE);
}

void exit_on_column_index_error (int base) {
    fprintf(stderr, "Column index must be between 1 and %d.\n\n", base);
    exit(EXIT_FAILURE);
}

void exit_on_slope_index_error (int base) {
    int slope_count = count_all_slopes(base);
    fprintf(stderr, "Slope index must be between 1 and %d.\n\n", slope_count);
    exit(EXIT_FAILURE);
}

void print_selected_cells(int base, int* selected_cell_indices){
    struct single_array_square square;
    initialize_square(&square, base);
    square.cells = (int *) malloc (sizeof(int) * (square.size + 1));

    print_int_square(&square, selected_cell_indices);
    printf("\n");
    free (square.cells);
}

int main (int argc, char *argv[]) {
    // Variables for getopt_long
    int opt = 0;
    int long_index = 0;
    static struct option long_options[] = {
        {"row", required_argument, 0, 'r'},
        {"column", required_argument, 0, 'c'},
        {"cross", required_argument, 0, 'x'},
        {"corner", required_argument, 0, 'j'},
        {"center", no_argument, 0, 'm'},
        {"horizontal-opposite", required_argument, 0, 'R'},
        {"vertical-opposite", required_argument, 0, 'C'},
        {"ascending-opposite", required_argument, 0, 'A'},
        {"descending-opposite", required_argument, 0, 'D'},
        {"ascending-slope", required_argument, 0, 'a'},
        {"descending-slope", required_argument, 0, 'd'},
        {0,0,0,0}
    };

    //Used by strtol to store memory addresses of erratic characters.
    char strtol_error = '\0';
    char* endptr = &strtol_error;

    //Domain logic variables
    int base = 0;
    int* selected_cells = NULL;

    // Assure that the very first program argument is an integer; enforce the syntax.
    if (optind < argc){
        base = atoi(argv[optind]);
        printf("\n");
        if (base <= 0){
            print_help(PROGRAM_NAME);
            return EXIT_FAILURE;
        }
    } else {
        print_help(PROGRAM_NAME);
        return EXIT_SUCCESS;
    }

    while((opt = getopt_long(argc, argv, "a:A:c:C:d:D:j:mr:R:x", long_options, &long_index)) != -1){
        switch(opt){
            case 'r': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);
                    int index_is_valid = check_row_index_validity (index, base);
                    if (index_is_valid){
                        selected_cells = select_row(index, base);
                    } else {
                        exit_on_row_index_error(base);
                    }
                }
                break;
            }

            case 'c': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);
                    int index_is_valid = check_column_index_validity (index, base);
                    if (index_is_valid){
                        selected_cells = select_column(index, base);
                    } else {
                        exit_on_column_index_error(base);
                    }
                }
                break;
            }

            case 'j': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);
                    selected_cells = select_corners(index, base);
                }
                break;
            }

            case 'm': {
                if (selected_cells == NULL)
                    selected_cells = select_square_center(base);
                break;
            }

            case 'x': {
                if (selected_cells == NULL){
                    selected_cells = select_slants(ALL, base);
                }
                break;
            }

            case 'R': {
                if (selected_cells == NULL){
                    selected_cells = malloc(sizeof(int)* 3);
                    int index = strtol(optarg, &endptr, 0);

                    int opposite_index = horizontal_opposite(index, base);

                    selected_cells[0] = index;
                    selected_cells[1] = opposite_index;
                }
                break;
            }

            case 'C': {
                if (selected_cells == NULL){
                    selected_cells = malloc(sizeof(int)* 3);
                    int index = strtol(optarg, &endptr, 0);

                    int opposite_index = vertical_opposite(index, base);

                    selected_cells[0] = index;
                    selected_cells[1] = opposite_index;
                }
                break;
            }

            case 'D': {
                if (selected_cells == NULL){
                    selected_cells = malloc(sizeof(int)* 3);
                    int index = strtol(optarg, &endptr, 0);

                    int opposite_index = descending_opposite(index, base);

                    selected_cells[0] = index;
                    selected_cells[1] = opposite_index;
                }
                break;
            }

            case 'A': {
                if (selected_cells == NULL){
                    selected_cells = malloc(sizeof(int)* 3);
                    int index = strtol(optarg, &endptr, 0);

                    int opposite_index = ascending_opposite(index, base);

                    selected_cells[0] = index;
                    selected_cells[1] = opposite_index;
                }
                break;
            }

            case 'd': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);
                    int index_is_valid = check_slope_index_validity (index, base);
                    if (index_is_valid){
                        selected_cells = select_descending_slope(index, base);
                    } else {
                        exit_on_slope_index_error(base);
                    }
                }
                break;
            }

            case 'a': {
                if (selected_cells == NULL){
                    int index = strtol(optarg, &endptr, 0);
                    int index_is_valid = check_slope_index_validity (index, base);
                    if (index_is_valid){
                        selected_cells = select_ascending_slope(index, base);
                    } else {
                        exit_on_slope_index_error(base);
                    }
                }
                break;
            }

            default: {
                print_help(PROGRAM_NAME);
                return EXIT_SUCCESS;
            }
        }
    }

    if (selected_cells == NULL){
        selected_cells = select_all_cells(base);
    }

    // After parsing the all the getopt switches and arguments...
    if (*endptr != '\0')
        exit_on_input_error();

    if (errno != 0)
        exit_on_error();

    print_selected_cells(base, selected_cells);

    return EXIT_SUCCESS;
}