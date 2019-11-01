#include<bits/stdc++.h>

using namespace std;


//return erntringer number
int erntringer(int n, int k){
    
    int dp[n+1][k+1];

    memset(dp,0,sizeof(dp));

    //base cases
    //k == 0, n==0
    dp[0][0] = 1;

    //k == 0
    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
    }

    //find dp[i][j]
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][i-j];
        }
    }

    return dp[n][k];
}

//driver program

int main(){
    int n = 4;
    int k = 3;

    cout << "Erntringer number for n = " << n << " and k = " << k << " is :" << erntringer(n,k);

    return 0;
}