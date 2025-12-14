#include <stdio.h>
#include <stdlib.h>

void echanger(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void triBulle(int T[], int taille)
{
    for (int i = 0; i < taille - 1; i++)
        for (int j = 0; j < taille - i - 1; j++)
            if (T[j] > T[j+1])
                echanger(&T[j], &T[j+1]);
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
    triBulle(T, taille);
    printf("Tableau trie:\n");
    affichage(T, taille);
    return 0;
}
