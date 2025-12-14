#include <stdio.h>
#include <stdlib.h>

void echanger(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void tas(int T[], int taille, int i)
{
    int maxIdx = i;
    int g = 2 * i + 1;
    int d = 2 * i + 2;
    if (g < taille && T[g] > T[maxIdx])
        maxIdx = g;

    if (d < taille && T[d] > T[maxIdx])
        maxIdx = d;

    if (maxIdx != i)
    {
        echanger(&T[i], &T[maxIdx]);
        tas(T, taille, maxIdx);
    }
}

void triTas(int T[], int taille)
{
    for (int i = taille/2 - 1; i >= 0; i--)
        tas(T, taille, i);

    for (int i = taille - 1; i >= 0; i--)
    {
        echanger(&T[0], &T[i]);
        tas(T, i, 0);
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
    int T[] = {20, 12, 10, 35, 25, 0};
    printf("Tableau non trie:\n");
    affichage(T, taille);
    triTas(T, taille);
    printf("Tableau trie:\n");
    affichage(T, taille);
    return 0;
}
