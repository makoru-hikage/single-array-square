#include "initialisation_tests.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

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
        printf("Index: %d \n", i);
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
    csq.cells = (char *) malloc (sizeof(char) * (csq.size + 1));
    memcpy((char*)csq.cells, sator, csq.size + 1);

    int root_index = (uintptr_t)csq.cells;
    printf("Root Address: %d \n", root_index);
    printf("Root: %d \n", root_index - root_index); 
    printf("-----------\n");

    for (int i = 1; i <= csq.size; i++){
        printf("Index Address: %d \n", csq.cells + i);
        printf("Index: %d \n", i);
        printf("Content: %c \n", ((char *)csq.cells)[i]);
        printf("-----------\n");
    }

    free(csq.cells);
    printf("==========END\n");
}