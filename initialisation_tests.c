#include "initialisation_tests.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "magic_square.h"

int zero_to_twenty_five[26];

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
    struct magic_square isq;

    initialize_square(&isq, base);
    isq.cells = &zero_to_twenty_five;

    int root_index = (uintptr_t)isq.cells;
    printf("Root Address: %d \n", root_index);
    printf("Root: %d \n", root_index - root_index);
    printf("-----------\n");

    for (int i = 1; i <= isq.size; i++){
        isq.cells++;
        *(int *)isq.cells = i;
        printf("Index Address: %d \n", isq.cells);
        printf("Index: %d \n", isq.cells - root_index);
        printf("Content: %d \n", *(int *)isq.cells);
        printf("-----------\n");
    }

    printf("==========END\n");
}

void test_char_square(){
    printf("START==========\n");
    int base = 5;
    struct magic_square sq;

    initialize_square(&sq, base);
    sq.cells = &sator;

    int root_index = (uintptr_t)sq.cells;
    printf("Root Address: %d \n", root_index);
    printf("Root: %d \n", root_index - root_index); 
    printf("-----------\n");

    for (int i = 1; i <= sq.size; i++){
        sq.cells++;
        printf("Index Address: %d \n", sq.cells);
        printf("Index: %d \n", sq.cells - root_index);
        printf("Content: %c \n", *(char* )sq.cells);
        printf("-----------\n");
    }

    printf("==========END\n");
}