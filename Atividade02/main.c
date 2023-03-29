#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int *vector, int size)
{

    int i, j, aux;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < (size - 1); j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(&vector[j], &vector[j + 1]);
            }
        }
    }
    

    
}

int cura(int *vector1, int *vector2, int nDoses)
{
    for (int i = 0; i < nDoses; i++)
    {
        if (vector1[i] >= vector2[i])
        {
            
            printf("nao");
            return 0;
        }
    }
    printf("sim");
    return 1;
}

int main()
{
    int nDoses, result;
    int *vectorMOrg = malloc(sizeof(int) * nDoses);
    int *vectorPot = malloc(sizeof(int) * nDoses);
    scanf("%d", &nDoses);
    for (int i = 0; i < nDoses; i++)
    {
        scanf("%d", &vectorMOrg[i]);
    };
    for (int i = 0; i < nDoses; i++)
    {

        scanf("%d", &vectorPot[i]);
    };
    bubble_sort(vectorMOrg, nDoses);
    
    bubble_sort(vectorPot, nDoses);
    result = cura(vectorMOrg, vectorPot, nDoses);
}