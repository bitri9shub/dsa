#include "HEADERS.h"


void insertValue(tree **myRoot, int newValue)
{
    if (*myRoot != NULL)
    {
        if ((*myRoot)->value > newValue)
        {
            insertValue(&((*myRoot)->LC), newValue);
        }
        else
        {
            insertValue(&((*myRoot)->RC), newValue);
        }
    }
    else
    {
        *myRoot = (tree *) malloc(sizeof(tree));
        (*myRoot)->value = newValue;
        (*myRoot)->LC = NULL;
        (*myRoot)->RC = NULL;
    }
}

void readTree(tree *root)
{
    if (root != NULL)
    {
        readTree(root->LC);
        printf("%d ", root->value);
        readTree(root->RC);
    }
}


int deleteMin(tree **myRoot)
{
    int minValue;

    if ((*myRoot)->LC == NULL)
    {
        minValue = (*myRoot)->value;
        tree *temp = *myRoot;
        *myRoot = (*myRoot)->RC;
        free(temp);
        return minValue;
    }
    else
    {
        return deleteMin(&((*myRoot)->LC));
    }
}
