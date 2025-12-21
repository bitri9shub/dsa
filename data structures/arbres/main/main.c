#include "HEADERS.h"

int main()
{
    tree *root;
    insertValue(&root, 2);
    insertValue(&root, 4);
    insertValue(&root, 15);
    insertValue(&root, 0);
    insertValue(&root, 19);
    insertValue(&root, 1);

    printf("Initialize tree: ");
    readTree(root);
    printf("\n");


    // ######## find & delete min value ########
    int minValue = deleteMin(&root);
    printf("delete min value: ");
    readTree(root);
    printf("\n");

    minValue = deleteMin(&root);
    printf("re-delete min value: ");
    readTree(root);
    printf("\n");

    minValue = deleteMin(&root);
    printf("re-delete min value: ");
    readTree(root);
    printf("\n");

    return 0;
}
