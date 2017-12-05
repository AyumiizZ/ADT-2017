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
    TYPE_NODEPTR New;
    New = (TYPE_NODEPTR)malloc(sizeof(TYPE_NODE));
    New->Info = Item;
    New->Next = NULL;
    return New;
}
TYPE_NODEPTR DeleteFirst(TYPE_NODEPTR List)
{
    TYPE_NODEPTR Point;
    Point = List;
    List = List->Next;
    Point->Next = NULL;
    return Point;
}
TYPE_NODEPTR DeleteAfter(TYPE_NODEPTR Point)
{
    TYPE_NODEPTR Point2;
    Point2 = Point->Next;
    Point->Next = Point2->Next;
    Point2->Next = NULL;
    return Point2;
}
TYPE_NODEPTR DeleteLast(TYPE_NODEPTR List)
{
    TYPE_NODEPTR Prior, Current;
    if (List->Next != NULL)
    {
        Prior = List;
        Current = List;
        while (Current->Next != NULL)
        {
            Prior = Current;
            Current = Current->Next;
        }
    }
    if(Prior, Current)
    {
        return DeleteFirst(List);
    }
    return DeleteAfter(Prior);
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