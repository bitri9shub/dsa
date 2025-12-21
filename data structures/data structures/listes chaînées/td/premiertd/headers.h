#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int value;
    struct cell *next;
} cell;

cell* initializeCell(int);
void addHead(cell **, int);
void printCells(cell *);
int maxHead_iterative(cell *);
int maxHead_recursive(cell *);
cell* concatenateLists(cell **, cell *);
void extractList(cell *, cell **, cell **);




#endif // HEADERS_H_INCLUDED
