#include <stdio.h>

struct lista {
    int valor;
    struct lista *prox;
};

int merge(int *vector, int begin, int middle, int end) {
    int *aux = malloc(sizeof(int) * (end - begin + 1));
    int i = begin, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (vector[i] < vector[j]) {
            aux[k] = vector[i];
            i++;
        } else {
            aux[k] = vector[j];
            j++;
        }
        k++;
    }
    while (i <= middle) {
        aux[k] = vector[i];
        i++;
        k++;
    }
    while (j <= end) {
        aux[k] = vector[j];
        j++;
        k++;
    }
    for (i = begin; i <= end; i++) {
        vector[i] = aux[i - begin];
    }
    free(aux);
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

int main(){

}