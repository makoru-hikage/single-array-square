#include "initialisation_tests.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

char sator[26] = { ' ',
    's','a','t','o','r',
    'a','r','e','p','o',
    't','e','n','e','t',
    'o','p','e','r','a',
    'r','o','t','a','s'
};

void test_int_square(){
    printf("START==========\n");
    int base = 5;
    struct single_array_square isq;

    initialize_square(&isq, base);
    isq.cells = (int *) malloc (sizeof(int) * (isq.size + 1));

    int root_index = (uintptr_t)isq.cells;
    printf("Root Address: %d \n", root_index);
    printf("Root: %d \n", root_index - root_index);
    printf("-----------\n");

    for (int i = 1; i <= isq.size; i++){
        ((int *)isq.cells)[i] = i;
        printf("Index Address: %d \n", (int *)isq.cells + i);
        printf("Index: %d \n", ((int *)isq.cells)[i]);
        printf("Content: %d \n", ((int *)isq.cells)[i]);
        printf("-----------\n");
    }
    free(isq.cells);
    printf("==========END\n");
}

void test_char_square(){
    printf("START==========\n");
    int base = 5;
    struct single_array_square csq;

    initialize_square(&csq, base);
    csq.cells = &sator;

    int root_index = (uintptr_t)csq.cells;
    printf("Root Address: %d \n", root_index);
    printf("Root: %d \n", root_index - root_index); 
    printf("-----------\n");

    for (int i = 1; i <= csq.size; i++){
        csq.cells++;
        printf("Index Address: %d \n", csq.cells);
        printf("Index: %d \n", csq.cells - root_index);
        printf("Content: %c \n", *(char* )csq.cells);
        printf("-----------\n");
    }

    printf("==========END\n");
}