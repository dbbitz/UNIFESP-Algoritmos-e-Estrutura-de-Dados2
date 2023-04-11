#include <stdio.h>
#include <stdlib.h>

/* Definição da estrutura da lista encadeada */
typedef struct node
{
    int key;
    struct node *next;
} Node;

/* Função que mescla duas sublistas ordenadas */
Node *merge(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        Node *merged;
        if (list1->key < list2->key)
        {
            merged = list1;
            merged->next = merge(list1->next, list2);
        }
        else
        {
            merged = list2;
            merged->next = merge(list1, list2->next);
        }
        return merged;
    }
}

void print_list(Node *list)
{
    if (list != NULL)
    {
        printf("%d ", list->key);
        print_list(list->next);
    }
}

Node *divide(Node *list, int *level)
{
    Node *rapido = list;
    Node *lento = list;

    while (rapido->next != NULL && rapido->next->next != NULL)
    {
        rapido = rapido->next->next;
        lento = lento->next;
        }

    struct Node *meio = lento->next;
    lento->next = NULL;

    return meio;
}

Node *merge_sort(Node *list, int *level)
{
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    else
    {
        Node *metade1 = list;
        Node *metade2 = divide(list, level);

        level += 1;

        metade1 = merge_sort(metade1, level);
        metade2 = merge_sort(metade2, level);

        return merge(metade1, metade2);
    }
}

int main()
{
    /* Leitura da entrada */
    int n;
    scanf("%d", &n);
    Node *list = NULL;
    Node *list2 = NULL;

    int i;
    printf("\nDigite os elementos da lista 1: ");
    for (i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        Node *new_node = malloc(sizeof(Node));
        new_node->key = key;
        new_node->next = list;
        list = new_node;
    }

    int level = 0;
    Node *sort_list;
    sort_list = merge_sort(list, &level);
    print_list(sort_list);
    printf("\nLevel: %d", level);

    return 0;
}
