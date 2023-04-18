#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianaDeTres(int array[], int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    if (array[inicio] > array[meio])
    {
        swap(&array[inicio], &array[meio]);
    }
    if (array[inicio] > array[fim])
    {
        swap(&array[inicio], &array[fim]);
    }
    if (array[meio] > array[fim])
    {
        swap(&array[meio], &array[fim]);
    }
    swap(&array[meio], &array[fim]);

    return array[fim];
}

int partition(int array[], int inicio, int fim, int pivo)
{
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

int quicksortMax(int array[], int inicio, int fim, int height)
{
    if (inicio >= fim)
    {
        return height;
    }
    int pivo = partition(array, inicio, fim, array[fim]);

    printf("\n\nPivo: %d, Altura: %d\n ", pivo, height);

    imprimeVetor(array, fim, inicio, pivo - 1);
    printf(" | %d | ", array[pivo]);
    imprimeVetor(array, fim, pivo + 1, fim);

    int left = quicksortMax(array, inicio, pivo - 1, height + 1);
    int right = quicksortMax(array, pivo + 1, fim, height + 1);
    printf("\nLeft: %d Right: %d\n", left, right);
    return left > right ? left : right;
}

int quicksortMin(int array[], int inicio, int fim, int height)
{
    if (inicio >= fim)
    {
        return height;
    }
    int pivo = partition(array, inicio, fim, array[fim]);

    printf("\n\nPivo: %d, Altura: %d\n ", pivo, height);

    imprimeVetor(array, fim, inicio, pivo - 1);
    printf(" | %d | ", array[pivo]);
    imprimeVetor(array, fim, pivo + 1, fim);

    int left = quicksortMin(array, inicio, pivo - 1, height + 1);
    int right = quicksortMin(array, pivo + 1, fim, height + 1);
    printf("\nLeft: %d Right: %d\n", left, right);
    return left > right ? right : left;
}

// QuickSort usando mediana de 3 como pivô

int quicksortMedianaDeTresMax(int array[], int inicio, int fim, int height)
{
    if (inicio >= fim)
    {
        return height;
    }
    int pivo = medianaDeTres(array, inicio, fim);
    int indexPivo = partition(array, inicio, fim, pivo);
    printf("\n\nPivo: %d Index Pivo: %d Altura: %d\n ", pivo, indexPivo, height);
    imprimeVetor(array, fim, inicio, indexPivo - 1);
    printf(" | %d | ", pivo);
    imprimeVetor(array, fim, indexPivo + 1, fim);
    int left = quicksortMedianaDeTresMax(array, inicio, indexPivo - 1, height + 1);
    int right = quicksortMedianaDeTresMax(array, indexPivo + 1, fim, height + 1);
    return left > right ? left : right;
}

int quicksortMedianaDeTresMin(int array[], int inicio, int fim, int height)
{
    if (inicio >= fim)
    {
        return height;
    }
    int pivo = medianaDeTres(array, inicio, fim);
    int indexPivo = partition(array, inicio, fim, pivo);
    printf("\n\nPivo: %d Index Pivo: %d Altura: %d\n ", pivo, indexPivo, height);
    imprimeVetor(array, fim, inicio, indexPivo - 1);
    printf(" | %d | ", pivo);
    imprimeVetor(array, fim, indexPivo + 1, fim);
    int left = quicksortMedianaDeTresMin(array, inicio, indexPivo - 1, height + 1);
    int right = quicksortMedianaDeTresMin(array, indexPivo + 1, fim, height + 1);
    return left > right ? right : left;
}

void imprimeVetor(int array[], int size, int inicio, int fim)
{
    for (int i = inicio; i <= fim; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int *vector = malloc(sizeof(int) * n);
    int *vectorAux = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
        vectorAux[i] = vector[i];
    }
    int MaxHeightQuickSort = quicksortMax(vector, 0, n - 1, 0);
    int MinHeightQuickSort = quicksortMin(vector, 0, n - 1, 0);

    int MaxHeightQuickSortMedianaDeTres = quicksortMedianaDeTresMax(vectorAux, 0, n - 1, 0);
    int MinHeightQuickSortMedianaDeTres = quicksortMedianaDeTresMin(vectorAux, 0, n - 1, 0);

    printf("\nMax Height QuickSort: %d\n", MaxHeightQuickSort);
    printf("\nMin Height QuickSort: %d\n", MinHeightQuickSort);
    printf("\nDiferenca: %d\n", MaxHeightQuickSort - MinHeightQuickSort);

    printf("\nMax Height QuickSort Mediana de 3: %d\n", MaxHeightQuickSortMedianaDeTres);
    printf("\nMin Height QuickSort Mediana de 3: %d\n", MinHeightQuickSortMedianaDeTres);
    printf("\nDiferenca: %d\n", MaxHeightQuickSortMedianaDeTres - MinHeightQuickSortMedianaDeTres);
    free(vector);
    free(vectorAux);

    return 0;
}