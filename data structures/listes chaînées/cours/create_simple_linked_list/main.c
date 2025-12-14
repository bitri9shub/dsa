#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int value;
    struct cell *next;
} cell;

cell* initializeCell(int value)
{
    cell *newCell;
    newCell = (cell*) malloc(sizeof(cell));
    newCell->value = value;
    newCell->next = NULL;
    return newCell;
}

int elementsNumber(cell *head)
{
    int n = 0;
    if(head)
    {
        do{
            n++;
            head = head->next;
        }while(head != NULL);
    }
    return n;
}

void printCells(cell *head)
{
    if(head)
    {
        do{
            printf("val: %d\n", head->value);
            printf("next: %p\n", head->next);
            head = head->next;
        }while(head != NULL);
    }
}

void addHead(cell **cell1, cell *cell2)
{
    cell2->next = *cell1;
    *cell1 = cell2;
}

void addTail(cell **cell1, cell *cell2)
{
    cell *tmp = *cell1;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = cell2;
}

void addMid(cell **cell1, cell *cell2, int index)
{
    cell *tmp = *cell1;
    for(int i = 0; i < index; i++)
        tmp = tmp->next;
    cell2->next = tmp->next;
    tmp->next = cell2;
}

void delHead(cell **cell1)
{
    cell *tmp = *cell1;
    *cell1 = (*cell1)->next;
    free(tmp);
}

void delTail(cell **cell1)
{
    cell *tmp = *cell1;
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
}

void delMid(cell **cell1, int index)
{
    cell *tmp = *cell1;
    for(int i = 0; i < index - 1; i++)
        tmp = tmp->next;
    tmp->next = tmp->next->next;
}

void updateHead(cell **cell1, int value)
{
    (**cell1).value = value;
    // (*cell1)->value = value; CORRECT
}

void updateTail(cell **cell1, int value)
{
    cell *tmp = *cell1;
    while(tmp->next != NULL)
        tmp = tmp->next;
    // tmp->value = value; CORRECT
    (*tmp).value = value;
}

void updateMid(cell **cell1, int index, int value)
{
    cell *tmp = *cell1;
    for(int i = 0; i < index; i++)
        tmp = tmp->next;
    // tmp->value = value; CORRECT
    (*tmp).value = value;
}


int main()
{
    int cellsNo;

    cell *noeud0 = initializeCell(5);
    cell *noeud1 = initializeCell(10);
    cell *noeud2 = initializeCell(15);
    cell *noeud3 = initializeCell(20);
    cell *noeud4 = initializeCell(0);
    cell *noeud5 = initializeCell(25);
    cell *noeud6 = initializeCell(18);

    noeud0->next = noeud1;
    noeud1->next = noeud2;
    noeud2->next = noeud3;

    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    cellsNo = elementsNumber(noeud0);
    printf("this linked list has %d elements\n", cellsNo);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    addHead(&noeud0, noeud4);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    addTail(&noeud0, noeud5);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    addMid(&noeud0, noeud6, 3);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    delHead(&noeud0);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    delTail(&noeud0);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    delMid(&noeud0, 2);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    updateHead(&noeud0, 0);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    updateTail(&noeud0, 50);
    printCells(noeud0);

    printf("\n");
    printf("############################################\n");
    printf("\n");

    updateMid(&noeud0, 2, 25);
    printCells(noeud0);

    return 0;
}
