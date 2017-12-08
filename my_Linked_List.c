#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char val;
    struct node *Next;
} TYPE_NODE;

void print(TYPE_NODE *head)
{
    TYPE_NODE *current = head;
    if (head == NULL)
        printf("EMPTY");
    while (current != NULL)
    {
        printf("%c ", current->val);
        current = current->Next;
    }
    printf("\n");
}
void addFirst(TYPE_NODE **head, char val)
{
    TYPE_NODE *new_node;
    new_node = malloc(sizeof(TYPE_NODE));

    new_node->val = val;
    new_node->Next = *head;
    *head = new_node;
}
void addLast(TYPE_NODE *head, char val)
{
    TYPE_NODE *new_node;
    new_node = malloc(sizeof(TYPE_NODE));
    new_node->val = val;
    new_node->Next = NULL;
    while(head->Next != NULL)
    {
        head = head->Next;
    }
    head->Next = new_node;
}
char removeFirst(TYPE_NODE **head)
{
    char retval = '\0';
    TYPE_NODE *next_node = NULL;
    if (*head == NULL)
        return '\0';
    next_node = (*head)->Next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return retval;
}
char removeLast(TYPE_NODE *head)
{
    char retval = '\0';
    if (head->Next == NULL)
    {
        retval = head->val;
        free(head);
        return retval;
    }
    TYPE_NODE *current = head;
    while (current->Next->Next != NULL)
    {
        current = current->Next;
    }
    retval = current->Next->val;
    free(current->Next);
    current->Next = NULL;
    return retval;
}
char removeAt(TYPE_NODE **head, int n)
{
    int i = 0;
    char retval = '\0';
    TYPE_NODE *current = *head;
    TYPE_NODE *temp_node = NULL;

    if (n == 0)
    {
        return removeFirst(head);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (current->Next == NULL)
            return retval;
        current = current->Next;
    }
    temp_node = current->Next;
    retval = temp_node->val;
    current->Next = temp_node->Next;
    free(temp_node);
    return retval;
}
int main()
{
    char temp;
    TYPE_NODE *test_list = malloc(sizeof(TYPE_NODE));
    test_list->val = '9';
    temp = removeFirst(&test_list);
    print(test_list);
    addLast(test_list,'4');
    print(test_list);
    addFirst(&test_list, '1');
    print(test_list);
    addFirst(&test_list, '2');
    print(test_list);
    addLast(test_list,'3');
    print(test_list);
    return EXIT_SUCCESS;
}

// #include <stdio.h>
// #include <stdlib.h>
// struct LinkedLists
// {
//     char Data;
//     struct LinkedLists *Next;
// } LinkedList;
// struct LinkedLists *LL;
// void print(struct LinkedLists *List)
// {
//     if (List->Next == NULL)
//     {
//         printf("EMPTY");
//     }
//     while (List->Next != NULL)
//     {
//         List = List->Next;
//         printf("%d ", List->Data);
//     }
//     printf("\n");
// }
// void InsertFirst(struct LinkedLists *List, char Data)
// {
//     if (List->Next == NULL)
//     {
//         List->Next = (struct LinkedLists *)malloc(sizeof(struct LinkedLists));
//         List->Next->Data = Data;
//         List->Next->Next = NULL;
//     }
//     else
//     {
//         struct LinkedLists *Point;
//         Point->Data = Data;
//         Point->Next = List->Next;
//         List->Next = Point;
//     }
// }
// int main()
// {
//     // struct LinkedLists *Point, *Point2;
//     LL = (struct LinkedLists *)malloc(sizeof(struct LinkedLists));
//     LL->Next = NULL;
//     while (1)
//     {
//         char Data;
//         scanf("%c", &Data);
//         InsertFirst(LL, Data);
//         print(LL);
//     }
//     return 0;
// }