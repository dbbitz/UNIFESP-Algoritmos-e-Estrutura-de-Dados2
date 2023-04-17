#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int inicio, int fim)
{
    int pivo = array[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (array[j] <= pivo)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[fim]);

    return i + 1;
}
void quicksort(int array[], int inicio, int fim, int *level, int aux)
{
    if (inicio < fim)
    {
        int pivo = partition(array, inicio, fim);
        quicksort(array, inicio, pivo - 1, level, aux + 1);
        quicksort(array, pivo + 1, fim, level, aux + 1);
        if (aux > *level)
        {
            *level = aux;
        }
    }
}

// QuickSort usando mediana de 3 como pivô

int medianaDeTres(int array[], int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    if (array[inicio] > array[meio])
        swap(&array[inicio], &array[meio]);
    if (array[inicio] > array[fim])
        swap(&array[inicio], &array[fim]);
    if (array[meio] > array[fim])
        swap(&array[meio], &array[fim]);
    return array[meio];
}

int partitionMedianaDeTres(int array[], int inicio, int fim, int pivo)
{
    int i = inicio - 1;
    int j;
    for (j = inicio; j < fim; j++)
    {
        if (array[j] <= pivo)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[fim]);
    return i + 1;
}

void quicksortMedianaDeTres(int array[], int inicio, int fim, int *level, int aux)
{
    if (inicio < fim)
    {
        int pivo = medianaDeTres(array, inicio, fim);
        int indicePivo = partitionMedianaDeTres(array, inicio, fim, pivo);
        quicksortMedianaDeTres(array, inicio, pivo - 1, level, aux + 1);
        quicksortMedianaDeTres(array, pivo + 1, fim, level, aux + 1);
        if (aux > *level)
        {
            *level = aux;
        }
    }
}

void imprimeVetor(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int *vector = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }
    int levelQuickSort = 0;
    int levelQuickSortMedianaDeTres = 0;
    int aux = 0;
    int *vectorAux = malloc(sizeof(int) * n);
    vectorAux = vector;
    quicksort(vector, 0, n - 1, &levelQuickSort, aux);
    imprimeVetor(vector, n);
    quicksortMedianaDeTres(vectorAux, 0, n - 1, &levelQuickSortMedianaDeTres, aux);
    printf("%d\n", levelQuickSort);
    printf("%d", levelQuickSortMedianaDeTres);
}