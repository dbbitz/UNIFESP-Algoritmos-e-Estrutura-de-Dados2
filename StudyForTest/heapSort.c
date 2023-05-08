#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void max_heapfy(int *vector, int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && vector[left] > vector[largest])
    {
        largest = left;
    }
    if (right < size && vector[right] > vector[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&vector[i], &vector[largest]);
        max_heapfy(vector, size, largest);
    }

}

void build_max_heap(int *vector, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        max_heapfy(vector, size, i);
    }
}

int heap_extract_max(int *vector, int *size)
{
    if (*size < 1)
    {
        printf("Heap underflow\n");
        return -1;
    }
    int max = vector[0];
    vector[0] = vector[*size - 1];
    *size = *size - 1;
    max_heapfy(vector, *size, 0);
    printf("Maximo extraido: %d\n", max);
    return max;
}

void heap_sort(int *vector, int size)
{
    build_max_heap(vector, size);
    imprime(vector, size);
    int V[size];
    int *tam = size;
    for (int i = size-1; i >= 0; i--)
    {
        V[i] = heap_extract_max(vector, &tam);
    }
    imprime(V, size);
}

void imprime(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
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
    heap_sort(vector, n);
}