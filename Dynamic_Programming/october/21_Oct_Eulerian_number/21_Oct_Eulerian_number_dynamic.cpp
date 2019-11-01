//dynamic eulerian

#include<bits/stdc++.h>

using namespace std;

int eulerian(int n, int m){
    int dp[n+1][m+1];

    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i > j){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = ((i-j)*dp[i-1][j-1])+((j+1)*dp[i-1][j]);
                }
                
            }
        }
    }
    return dp[n][m];
}

//driver code
int main(){
    int n = 3, m = 1;

    cout << "Eulerian (" << n << "," << m<< ") is " << eulerian(n,m);

    return 0;
}