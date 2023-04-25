#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeVetor(char *vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", vetor[i]);
    }
}

int main()
{
    int nWords, sizeKey;
    printf("Insira o número de palavras a serem ordenadas: ");
    scanf("%d", &nWords);
    printf("Insira o tamanho da chave: ");
    scanf("%d", &sizeKey);
    printf("Insira a chave: ");
    char key[sizeKey];
    scanf("%s", key);
    printf("Insira as palavras: ");
    char *words[nWords][100];
    for (int i = 0; i < nWords; i++)
    {
        scanf("%s", words[i]);
    }
    imprimeVetor(&words, nWords);
}