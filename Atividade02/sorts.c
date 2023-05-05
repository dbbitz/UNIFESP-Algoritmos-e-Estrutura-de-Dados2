#include <stdio.h>

//Métodos de ordenação

int selection_sort(int *vector, int size) {
    int i, j, min, aux;
    for (i = 0; i < (size - 1); i++) {
        min = i;
        for (j = (i + 1); j < size; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        if (vector[i] != vector[min]) {
            aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
        }
    }
}

int bubble_sort(int *vector, int size) {
    int i, j, aux;
    for (i = 0; i < (size - 1); i++) {
        for (j = 0; j < (size - 1); j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

int swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int insertion_sort(int *vector, int size) {
    int i, j, aux;
    for (i = 1; i < size; i++) {
        aux = vector[i];
        for (j = i; (j > 0) && (aux < vector[j - 1]); j--) {
            vector[j] = vector[j - 1];
        }
        vector[j] = aux;
    }
}

int merge_sort_recursive(int *vector, int begin, int end) {
    int middle;
    if (begin < end) {
        middle = (begin + end) / 2;
        merge_sort_recursive(vector, begin, middle);
        merge_sort_recursive(vector, (middle + 1), end);
        merge(vector, begin, middle, end);
    }
}

int main () {
    printf("Insira a quantidade de elementos: ");
    int size;
    scanf("%d", &size);
    int *vector = malloc(sizeof(int) * size);
    printf("Insira os elementos: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }
    printf("Vetor antes da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    selection_sort(*vector, size);
    printf("Vetor depois da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
}