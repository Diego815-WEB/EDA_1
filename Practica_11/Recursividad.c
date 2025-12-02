#include <stdio.h>

long long memo[100];

long long fib(int n)
{
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main()
{
    for (int i = 0; i < 100; i++)
        memo[i] = -1;

    int posiciones[] = {7, 21, 40, 71, 94};
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        printf("F(%d) = %lld\n", posiciones[i], fib(posiciones[i]));
    }

    return 0;
}