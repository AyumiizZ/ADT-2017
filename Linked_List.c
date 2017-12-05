#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char Info;
    struct Node *Next;
} TYPE_NODE;
typedef struct Node *TYPE_NODEPTR;
TYPE_NODEPTR NewNode(char Item)
{
    TYPE_NODEPTR N;
    N = (TYPE_NODEPTR)malloc(sizeof(TYPE_NODE));
    N->Info = Item;
    N->Next = NULL;
    return N;
}
void FreeNode(TYPE_NODEPTR N)
{
    free(N);
}
void InsertFirst(TYPE_NODEPTR *L, TYPE_NODEPTR N)
{
    N->Next = *L;
    *L = N;
}
void InsertAfter(TYPE_NODEPTR P, TYPE_NODEPTR N)
{
    N->Next = P->Next;
    P->Next = N;
}
void InsertLast(TYPE_NODEPTR P, TYPE_NODEPTR N)
{
    if (P->Next != NULL)
    {
        while (P->Next != NULL)
        {
            P = P->Next;
        }
        P->Next = N;
    }
    else
    {
        P->Next = N;
    }
    N->Next = NULL;
}
int main()
{
    printf("Hello World");
    return 0;
}