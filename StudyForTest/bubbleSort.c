#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


int bubble_sort(int *vector, int size)
{
    int max = size;
    printf("\nVetor a ser ordenado: ");
    imprime(vector, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < max-1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(&vector[j], &vector[j + 1]);
            }
        }
        max--;
    }
}


int bubble_sort_recursive(int *vector, int size){
    if(size == 1){
        return 0;
    }
    for(int i = 0; i < size; i++){
        if(vector[i] > vector[i+1]){
            swap(&vector[i], &vector[i+1]);
        }
    }
    bubble_sort_recursive(vector, size - 1);
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
    bubble_sort_recursive(vector, n);
    imprime(vector, n);
}