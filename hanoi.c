#include <stdio.h>
void solve(int n, char From, char To, char Mid)
{
    if (n == 1)
    {
        printf("Move %d from %c To %c\n", n, From, To);
    }
    else
    {
        solve(n - 1, From, Mid, To);
        printf("Move %d from %c To %c\n", n, From, To);
        solve(n - 1, Mid, To, From);
    }
}

int main()
{
    solve(4, 'A', 'C', 'B');
}