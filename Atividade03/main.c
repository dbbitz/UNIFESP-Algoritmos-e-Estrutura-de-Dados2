#include <stdio.h>
#include <stdlib.h>

/* Definição da estrutura da lista encadeada */
typedef struct node
{
    int key;
    struct node *next;
} Node;

/* Função que mescla duas sublistas ordenadas */
Node *merge(Node *list1, Node *list2, int *level)
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
            merged->next = merge(list1->next, list2, level);
        }
        else
        {
            merged = list2;
            merged->next = merge(list1, list2->next, level);
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
    Node *fast = list;
    Node *slow = list;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *middle = slow->next;
    slow->next = NULL;
    return middle;
}

Node *merge_sort(Node *list, int *level, int aux)
{
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    else
    {
        Node *list1 = list;
        Node *list2 = divide(list, level);

        list1 = merge_sort(list1, level, aux + 1);
        list2 = merge_sort(list2, level, aux + 1);
        if (aux > *level)
        {
            *level = aux;
        }

        return merge(list1, list2, level);
    }
}

int main()
{
    /* Leitura da entrada */
    int n;
    scanf("%d", &n);
    Node *list = NULL;

    int i;

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
    int aux = 1;
    Node *sort_list;
    sort_list = merge_sort(list, &level, aux);
    print_list(sort_list);
    printf("\n%d", level);
    return 0;
}
