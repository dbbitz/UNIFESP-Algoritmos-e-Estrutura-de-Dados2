#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprime(char **words, int nWords)
{
    for (int i = 0; i < nWords; i++)
    {
        printf("%s", words[i]);
        if (i < nWords - 1)
        {
            printf(" ");
        }
    }
}

void swap(char **words, int j, int i)
{
    char *aux = words[i];
    words[i] = words[j];
    words[j] = aux;
}

void max_heapify(char **words, int n, int i, int sizeKey, char *key)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    char word1[33], word2[33];
    remove_spaces(words[i]);
    strncpy(word1, words[i], 33);
    word1[strlen(words[i])] = '\0';

    if (l < n)
    {
        remove_spaces(words[l]);
        strncpy(word2, words[l], 33);
        word2[strlen(words[l])] = '\0';

        if (strcmp(word2, word1) > 0)
        {
            largest = l;
            strncpy(word1, word2, 33);
            word1[strlen(word2)] = '\0';
        }
    }

    if (r < n)
    {
        remove_spaces(words[r]);
        strncpy(word2, words[r], 33);
        word2[strlen(words[r])] = '\0';

        if (strcmp(word2, word1) > 0)
        {
            largest = r;
            strncpy(word1, word2, 33);
            word1[strlen(word2)] = '\0';
        }
    }

    if (largest != i)
    {
        swap(words, i, largest);
        max_heapify(words, n, largest, sizeKey, key);
    }
}

void remove_spaces(char *str)
{
    int i = 0, j = 0;
    while (str[j])
    {
        if (str[j] != ' ')
        {
            str[i++] = str[j];
        }
        j++;
    }
    str[i] = '\0';
}

void build_max_heap(char **words, int n, int sizeKey, char *key)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        max_heapify(words, n, i, sizeKey, key);
    }
}

void extract_max(char **words, int n, int sizeKey, char *key)
{
    swap(words, 0, n - 1);
    max_heapify(words, n - 1, 0, sizeKey, key);
}

void heap_sort(char **words, int n, int sizeKey, char *key)
{
    build_max_heap(words, n, sizeKey, key);
    for (int i = n - 1; i > 0; i--)
    {
        extract_max(words, i + 1, sizeKey, key);
    }
}

void wordHaveCaracterNotAlphabetic(char *word, int *haveCaracterNotAlphabetic)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (!isalpha(word[i]))
        {
            *haveCaracterNotAlphabetic = 1;
            printf("A palavra %s eh invalida", word);
            exit(0);
        }
    }
}

int main()
{
    int nWords, sizeKey;
    scanf("%d", &nWords);
    scanf("%d", &sizeKey);
    char key[sizeKey];
    scanf("%s", key);
    char **words = (char **)malloc(nWords * sizeof(char *));
    for (int i = 0; i < nWords; i++)
    {
        int haveCaracterNotAlphabetic = 0;
        words[i] = (char *)malloc(33 * sizeof(char));
        scanf("%s", words[i]);
        wordHaveCaracterNotAlphabetic(words[i], &haveCaracterNotAlphabetic);
    }

    heap_sort(words, nWords, sizeKey, key);
    imprime(words, nWords);
    return 0;
}