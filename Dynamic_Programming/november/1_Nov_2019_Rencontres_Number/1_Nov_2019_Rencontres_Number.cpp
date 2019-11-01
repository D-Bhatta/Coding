#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int binomialCoeff(int c[][MAX], int n, int k){

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=min(i,k); j++){
            //base case
            if(j == 0 || j == i){
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
            
        }
    }
}

int recontresNumber(int c[][MAX], int n, int m){

    int dp[n+1][m+1] = { 0 };
    //base cases
    dp[0][0] = 1;
    dp[1][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(j <= 1){
                if(j == 0 && i > 1){
                    dp[i][j] = (i-1)*(dp[i-1][0] + dp[i-2][0]);
                }
                else
                {
                    dp[i][j] = c[i][j] * dp[i-j][0];
                }
                

            }
        }
    }
    return dp[n][m];
}

//driver code
int main()
{
    int n = 7, m = 2;
    int c[MAX][MAX];
    binomialCoeff(c,n,m);

    cout << "Rencontres number for n = " << n << " and m = " << m << " is : " << recontresNumber(c,n,m);
    n = 3; m = 0;
    binomialCoeff(c,n,m);
    cout << "Rencontres number for n = " << n << " and m = " << m << " is : " << recontresNumber(c,n,m);
    n = 3; m = 1;
    binomialCoeff(c,n,m);
    cout << "Rencontres number for n = " << n << " and m = " << m << " is : " << recontresNumber(c,n,m);

    return 0;
}