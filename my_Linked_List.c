#include <stdio.h>
#include <stdlib.h>
struct LinkedLists
{
    char Data;
    struct LinkedLists *Next;
} LinkedList;
struct LinkedLists *LL;
void print(struct LinkedLists *List)
{
    if (List->Next == NULL)
    {
        printf("EMPTY");
    }
    while (List->Next != NULL)
    {
        List = List->Next;
        printf("%d ", List->Data);
    }
    printf("\n");
}
void InsertFirst(struct LinkedLists *List, char Data)
{
    if (List->Next == NULL)
    {
        List->Next = (struct LinkedLists *)malloc(sizeof(struct LinkedLists));
        List->Next->Data = Data;
        List->Next->Next = NULL;
    }
    else
    {
        struct LinkedLists *Point;
        Point->Data = Data;
        Point->Next = List->Next;
        List->Next = Point;
    }
}
int main()
{
    // struct LinkedLists *Point, *Point2;
    LL = (struct LinkedLists *)malloc(sizeof(struct LinkedLists));
    LL->Next = NULL;
    while (1)
    {
        char Data;
        scanf("%c", &Data);
        InsertFirst(LL, Data);
        print(LL);
    }
    return 0;
}