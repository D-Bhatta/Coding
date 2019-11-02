#include<bits/stdc++.h>

using namespace std;

int jacobsthal(int n){
    int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;


    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 2 * dp[i - 2];
    }

    return dp[n];
}

int jacobsthal_lucas(int n){
    int dp[n+1];

    dp[0] = 2;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 2 * dp[i-2];
    }

    return dp[n];
}


//driver program

int main(){

    int n = 5;

    cout << "Jacobsthal for n = " << n << " is :" << jacobsthal(n) << endl;

    cout << "Jacobsthal-Lucas for n = " << n << " is :" << jacobsthal_lucas(n) << endl;

    n = 17;

    cout << "Jacobsthal for n = " << n << " is :" << jacobsthal(n) << endl;

    cout << "Jacobsthal-Lucas for n = " << n << " is :" << jacobsthal_lucas(n) << endl;

    return 0;  

}