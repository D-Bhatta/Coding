/*Longest common Subsequence */

//naive implementation:
#include<stdio>
using namespace std;

int max(int a, int b);

//Returns the length of LCS for X[0...m-1], Y[0...n-1]
int lcs(char *x, char *y, int m, int n)
{
    if(m == 0 || n == 0)
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

//utility max function
int max(int a, int b)
{
    return (a>b)? a : b;
}

//driver code

int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int m = strlen(x);
    int y = strlen(y);

    cout << "Length of LCS is " << lcs(x,y,m,n)

    return 0;
}

//code from :https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/