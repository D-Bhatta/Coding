//dynamic dealnnoy

#include<bits/stdc++.h>
using namespace std;

int dealnnoy(int n, int m){
    int dp[m+1][n+1];

    //base case

    for(int i = 0; i <= m; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1];
        }
    }

    return dp[m][n];
}

//driver program

int main(){
    int n = 3, m  = 4;

    cout << "Dealnnoy(3,4) = " << dealnnoy(n,m);

    return 0;
}