#include <stdio.h>
#define MAXSTACK 10
int top = 0;
char stack[MAXSTACK];

void initStack()
{
    for (int i = 0; i < MAXSTACK; i++)
    {
        stack[i] = '\0';
    }
}

int isFull()
{
    return top == MAXSTACK;
}

int isEmpty()
{
    return top == 0;
}

void push(char inp)
{
    if (!isFull())
        stack[top++] = inp;
    else
        printf("Stack Overflow\n");
}

char pop()
{
    if (!isEmpty())
        return stack[--top];
    printf("Stack Underflow\n");
    return '\0';
}

void printStack()
{
    if (isEmpty())
        printf("EMPTY");
    else
        for (int i = 0; i < MAXSTACK; i++)
            if (i < top )
                printf("|%c| ", stack[i]);
            else
                printf("| | ");
    printf("\n");
}

int main()
{
    initStack();
    push('K');
    printStack();
    push('h');
    printStack();
    push('e');
    printStack();
    push('m');
    printStack();
    push('K');
    printStack();
    push('h');
    printStack();
    push('e');
    printStack();
    push('m');
    printStack();
    push('K');
    printStack();
    push('h');
    printStack();
    push('e');
    printStack();
    push('m');
    printStack();
    printf("pop %c\n",pop());
    printStack();
    printf("pop %c\n",pop());
    printStack();
    printf("pop %c\n",pop());
    printStack();
    printf("pop %c\n",pop());
    printStack();
    char x = pop();
    if(x != '\0')
        printf("pop %c\n",x);
    printStack();
    return 0;
}