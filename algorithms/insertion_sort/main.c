#include <stdio.h>
#include <stdlib.h>

void triInsertion(int T[], int taille)
{
    for (int i = 1; i < taille; i++)
    {
        int tmp = T[i];
        int j = i - 1;
        while(tmp < T[j] && j >= 0)
        {
            T[j+1] = T[j];
            j--;
        }
        T[j+1] = tmp;
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
    triInsertion(T, taille);
    printf("Tableau trie:\n");
    affichage(T, taille);
    return 0;
}
