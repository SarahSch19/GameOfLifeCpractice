/*
Game of Life practice
Sarah Schlegel
18.10.2021

output file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cells.h"
#include "output.h"

#define GRID_SIZE 15

void printMenu (void) {
    printf("Select option:\n") ;
    printf("0 - Quit\n") ;
    printf("1 - Next round\n") ;
    printf("2 - Save most recent to file.\n") ;
    printf("Enter option: ") ;
}

void printGrid (Cell** grid) {
    for (size_t i = 0; i < GRID_SIZE; i++) {
        for (size_t j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j].symbol) ;
        }
        printf("\n") ;
    }
}

void saveState(Cell** grid){
    /*
    "r"	    ouvre un fichier en lecture, le fichier doit exister
    "r+"	ouvre un fichier en lecture et écriture, le fichier doit exister
    "w"	    crée un fichier vide en écriture, écrase le contenu du fichier s’il existe déjà
    "w+"	crée un fichier vide en lecture et écriture, écrase le contenu du fichier s’il existe déjà
    "a" 	écriture en ajout à la fin d’un fichier, crée le fichier s’il n’existe pas
    "a+"	lecture et écriture en ajout à la fin d’un fichier, crée le fichier s’il n’existe pas
    */

    FILE* f = fopen("save.txt", "w");
    //char tmp[3] = "" ;
    if(f == NULL){
        return ;
    }
    /*
    char a[15] = "bonjour" ;
    strcat(a, " toi") ;
    a => "bonjour toi" ;

    sscanf(a, "%c %d", 'C', 1) //a => "C 1"
    */

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            fputc(grid[i][j].symbol, f) ;
            fputc(' ', f) ;
        }
        fputc('\n', f);
    }
    fclose(f);
}
