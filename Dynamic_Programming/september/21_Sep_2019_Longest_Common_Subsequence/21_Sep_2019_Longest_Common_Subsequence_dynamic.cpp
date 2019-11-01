//dynamic programmming implementation of LCS

#include<stdio>
using namespace std;

int max(int a, int b);

//returns length of of LCS for X[0..m-1], Y[0..n-1]

int lcs(char *x, char *y, int m, int n)
{
    int L[m+1][n+1];
    int i,j;

    //following steps build L[m+1][n+1] in bottom up fashion. Note that the last cell, i.e. L[i][j] contains length of lcs of x[0...i-1], y[0...j-1]
    for(i = 0; i <=m;  i++)
    {
        for(j = 0; j <= n; j++ )
        {
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else 
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
    return L[m][n];
}

//utility function to get max of 2 ints
int max(int a, int b)
{
    return (a>b)? a:b;
}

//driver function
int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int n = strlen(x);
    int m = strlen(y);

    cout << "LCS is " << lcs(x,y,m,n);

    return 0;
}