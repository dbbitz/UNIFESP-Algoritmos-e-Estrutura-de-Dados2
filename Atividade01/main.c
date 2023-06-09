#include <stdio.h>

int busca_binaria_recursiva(int *vector, int start, int end, int value, int cont)
{
    if (start > end) // O(1)
    {
        printf("%d nao foi encontrado", value);
        return -1;
    }
    int middle = (start + end) / 2; // O(1)
    if (vector[middle] == value)    // O(1)
    {
        printf("%d", cont);
        return cont;
    }
    if (vector[middle] > value) // O(1)
    {
        return busca_binaria_recursiva(vector, start, middle - 1, value, cont + 1); // T(n/2)
    }
    return busca_binaria_recursiva(vector, middle + 1, end, value, cont + 1); // T(n/2)
}

int main()
{
    int n, valor, result;
    scanf("%d", &n);
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &valor);
    result = busca_binaria_recursiva(vetor, 0, n - 1, valor, 0);
    free(vetor);
    return 0;
}