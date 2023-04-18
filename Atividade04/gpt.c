#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high]; // pivô é o último elemento
    int i = low - 1;
    for (int j = low; j < high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

int max_depth(int array[], int low, int high, int depth)
{
    if (low == high)
    {
        return depth;
    }
    int p = partition(array, low, high);
    int left_depth = max_depth(array, low, p - 1, depth + 1);
    int right_depth = max_depth(array, p + 1, high, depth + 1);
    return (left_depth > right_depth ? left_depth : right_depth);
}

int min_depth(int array[], int low, int high, int depth)
{
    if (low >= high)
    {
        return depth;
    }
    int p = partition(array, low, high);
    int left_depth = min_depth(array, low, p - 1, depth + 1);
    int right_depth = min_depth(array, p + 1, high, depth + 1);
    return (left_depth < right_depth ? left_depth : right_depth);
}
void imprime_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int max = max_depth(array, 0, n - 1, 0);
    int min = min_depth(array, 0, n - 1, 0);
    imprime_array(array, n);
    printf("%d\n", max - min);
    return 0;
}
