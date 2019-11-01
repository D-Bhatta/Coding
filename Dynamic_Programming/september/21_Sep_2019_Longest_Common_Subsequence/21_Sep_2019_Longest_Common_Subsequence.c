/*Longest common subsequeence */

//naive implementation

#include<stdio>
using namespace std;

int max(int a, int b);

//returns length of lcs for x[0...m-1], y[0...n-1]

int lcs(char *x,char *y,int m,int n)
{
    if(m==0 || n == 0)//if length is 0, return 0
        return 0;
    if(x[m-1] == y[n-1])
    {
        return 1 + lcs(x,y,m-1,n-1);
    }
    else
    {
        return max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
    }
    
}

//utility function for max of 2 ints
int max(int a, int b)
{
    return (a > b)? a:b;
}

//driver function to test above function
int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int m = strlen(x);
    int n = strlen(y);

    printf("Length of LCS is %d", lcs(x,y,m,n));

    return 0;
}