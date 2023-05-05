#include <stdio.h>
#include <stdlib.h>

// Métodos de ordenação

int swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int selection_sort(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (vector[j] < vector[i])
            {
                swap(&vector[j], &vector[i]);
            }
        }
    }
}

int selection_sort_recursive(int *vector, int size)
{
    if (size == 1)
    {
        return 0;
    }
    int min = 0;
    for (int i = 0; i < size; i++)
    {
        if (vector[i] < vector[min])
        {
            min = i;
        }
    }
    swap(&vector[0], &vector[min]);
    selection_sort_recursive(vector + 1, size - 1);
}

void imprime(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
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
    selection_sort_recursive(vector, n);
    printf("\n");
    imprime(vector, n);
}