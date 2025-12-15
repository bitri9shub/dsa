#include "headers.h"

cell * initializeCell(int v)
{
    cell *newCell;
    newCell = (cell*) malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = NULL;
    return newCell;
}

void printCells(cell *head)
{
    do{
        printf("value: %d\n", head->value);
        printf("next: %p\n", head->next);
        head = head->next;
        printf("\n");
    }while(head != NULL);
}

void addHead(cell **head, int v)
{
    cell *newCell = initializeCell(v);
    newCell->next = *head;
    *head = newCell;
}

int maxHead_iterative(cell *head)
{
    int max = head->value;
    do{
        if(max < head->value)
            max = head->value;
        head = head->next;
    }while(head != NULL);
    return max;
}

int maxHead_recursive(cell *head)
{
    if(head->next == NULL)
        return head->value;
    int restMax = maxHead_recursive(head->next);
    return (head->value > restMax) ? head->value : restMax;
}

cell* concatenateLists(cell **head1, cell *head2)
{
    cell *tmp = *head1;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = head2;
    return *head1;
}

void extractList(cell *head, cell **subList1, cell **subList2)
{
    *subList1 = NULL;
    *subList2 = NULL;
    do{
        if(head->value >= 0) {
            if(*subList1 != NULL) {
                addHead(subList1, head->value);
            } else {
                *subList1 = initializeCell(head->value);
            }
        } else {
            if(*subList2 != NULL){
                addHead(subList2, head->value);
            } else {
                *subList2 = initializeCell(head->value);
            }
        }
        head = head->next;
    }while(head != NULL);
}
