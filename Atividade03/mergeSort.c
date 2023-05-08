#include <stdio.h>

struct lista {
    int valor;
    struct lista *prox;
};

int merge(int *vector , int begin, int middle, int end) {
    int i, j, k;
    int n1 = middle - begin + 1;
    int n2 = end - middle;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = vector[begin + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vector[middle + 1 + j];
    }
    i = 0;
    j = 0;
    k = begin;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vector[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vector[k] = R[j];
        j++;
        k++;
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

int main(){

}