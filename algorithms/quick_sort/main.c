#include <stdio.h>
#include <stdlib.h>

void echanger(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int partition(int T[], int bas, int haut)
{
    int pivot = T[haut];
    int i = bas - 1;
    for(int j = bas; j < haut; j++)
    {
        if(T[j] <= pivot)
        {
            i++;
            echanger(&T[i], &T[j]);
        }
    }
    echanger(&T[i + 1], &T[haut]);
    return i + 1;
}

void triRapide(int T[], int bas, int haut)
{
    if (bas < haut)
    {
        int pi = partition(T, bas, haut);
        triRapide(T, bas, pi - 1);
        triRapide(T, pi + 1, haut);
    }
}

void affichage(int T[], int taille)
{
    for (int i = 0; i < taille; i++)
        printf("%d ", T[i]);
    printf("\n");
}

int main()
{
    int taille = 6;
    int T[] = {20, 25, 0, 35, 12, 10};
    printf("Tableau non trie:\n");
    affichage(T, taille);
    triRapide(T, 0, taille - 1);
    printf("Tableau trie:\n");
    affichage(T, taille);
    return 0;
}
