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
int main()
{
    printf("Hello World");
    return 0;
}