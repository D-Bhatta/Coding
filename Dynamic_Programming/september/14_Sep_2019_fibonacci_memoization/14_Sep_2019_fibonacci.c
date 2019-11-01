/*
a) Memoization (Top Down): The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.
*/
//Following is the memoized version for nth Fibonacci Number.


/*C program for memoized version for nth fibonacci number*/

#include<stdio.h>
#define NIL -1
#define MAX 100

int lookup[MAX];

/*Function to initialize NIL values in lookup table*/

void _initialize()
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        lookup[i] = NIL;
    }
}

/*function for nth fibonacci number*/
int fib(int n)
{
    if(lookup[n] == NIL)
    {
        if(n <= 1)
        {
            lookup[n] == n;
        }
        else
        {
            lookup[n]  = fib(n-1) + fib(n-2);
        }
        
    }

    return lookup[n];
}

int main()
{
    int n = 40;
    _initialize();
    printf("Fibonacci number is %d", fib(n));
    return 0;
}