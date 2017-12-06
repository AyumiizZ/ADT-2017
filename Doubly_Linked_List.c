#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char Info;
    struct node *Next;
    struct node *Prev;
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

void FreeNode(TYPE_NODEPTR Node)
{
    free(Node);
}

void InsertFirst(TYPE_NODEPTR List, TYPE_NODEPTR New)
{
    New->Next = List;
    List->Prev = New;
    List = New;
    List->Prev = NULL;
}
void InsertAfter(TYPE_NODEPTR *Point, TYPE_NODEPTR New)
{
    New->Next = Point->Next;
    New->Prev = Point;
    Point->Next->Prev = New;
    Point->Next = New;
}