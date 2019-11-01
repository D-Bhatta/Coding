/*
b) Tabulation (Bottom Up): The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.
*/
//Following is the tabulated version for nth Fibonacci Number.
#include<stdio.h>
int fib(int n)
{
    int f[n+1];
    int i;
    f[0] = 0; f[1] = 1;
    for(i = 2;i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main()
{
    int n = 9;
    printf("Fibonacci number is %d", fib(n));
    return 0;
}