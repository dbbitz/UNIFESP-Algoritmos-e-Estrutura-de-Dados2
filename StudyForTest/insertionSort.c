#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void imprime(int *vector, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
}

void insertion_sort(int *vector, int size)
{
    printf("Vetor a ser ordenado: ");
    imprime(vector, size);
    int i, j, aux;
    for (i = 1; i < size; i++)
    {
        aux = vector[i];
        for (j = i; j > 0 && vector[j - 1] > aux; j--)
        {
            vector[j] = vector[j - 1];
        }
        vector[j] = aux;
        imprime(vector, size);
    }
}

void insertion_sort_recursive(int *vector, int size)
{
    if (size == 1)
    {
        return;
    }
    insertion_sort_recursive(vector, size - 1);
    int aux = vector[size - 1];
    int j = size - 2;
    while (j >= 0 && vector[j] > aux)
    {
        vector[j + 1] = vector[j];
        j--;
    }
    vector[j + 1] = aux;
}

int main()
{
    printf("Insira a quantidade de elementos a serem ordenados: ");
    int n;
    scanf("%d", &n);
    int *vector = malloc(sizeof(int) * n);
    printf("\nInsira os elementos: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }
    insertion_sort(vector, n);
    printf("\n");
    imprime(vector, n);
}