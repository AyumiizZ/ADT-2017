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
void InsertFirst(TYPE_NODEPTR List, TYPE_NODEPTR New)
{
    New->Next = List;
    List = New;
}
void InsertAfter(TYPE_NODEPTR Point, TYPE_NODEPTR New)
{
    New->Next = Point->Next;
    Point->Next = New;
}
void InsertLast(TYPE_NODEPTR Point, TYPE_NODEPTR New)
{
    if (Point->Next != NULL)
    {
        while (Point->Next != NULL)
        {
            Point = Point->Next;
        }
        Point->Next = New;
    }
    else
    {
        Point->Next = New;
    }
    New->Next = NULL;
}
int main()
{
    printf("Hello World");
    return 0;
}