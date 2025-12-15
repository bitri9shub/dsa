#include "headers.h"

int main()
{
    // Création d'une liste
    cell *head = initializeCell(-50);
    addHead(&head, -40);
    addHead(&head, -30);
    addHead(&head, -20);
    addHead(&head, -10);
    addHead(&head, 0);
    addHead(&head, 10);
    addHead(&head, 20);
    addHead(&head, 30);
    addHead(&head, 40);
    addHead(&head, 50);

    printCells(head);

    // Ex1: Recherche de l'élément maximal

    printf("\n");
    printf("#############################################\n");
    printf("\n");

    int max_it = maxHead_iterative(head);
    printf("max iterative: %d\n", max_it);

    printf("\n");
    printf("#############################################\n");
    printf("\n");

    int max_rec = maxHead_recursive(head);
    printf("max recursive: %d\n", max_rec);

    printf("\n");
    printf("#############################################\n");
    printf("\n");

    // Ex2: Concaténer deux listes
    cell *L1 = initializeCell(17);
    addHead(&L1, 18);
    addHead(&L1, 19);
    addHead(&L1, 20);

    cell *L2 = initializeCell(13);
    addHead(&L2, 14);
    addHead(&L2, 15);
    addHead(&L2, 16);

    L1 = concatenateLists(&L1, L2);
    printCells(L1);

    // Ex3: Séparer une liste en deux sous listes
    cell *subList1;
    cell *subList2;

    extractList(head, &subList1, &subList2);

    printf("### sub-list 1 ###\n");
    printCells(subList1);
    printf("### sub-list 2 ###\n");
    printCells(subList2);

    // Ex4: Permuter deux places d'une liste




    return 0;
}
