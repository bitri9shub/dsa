#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int value;
    struct tree *LC;
    struct tree *RC;
} tree;

void insertValue(tree **, int);
void readTree(tree *);
int deleteMin(tree **);

#endif // HEADERS_H_INCLUDED
