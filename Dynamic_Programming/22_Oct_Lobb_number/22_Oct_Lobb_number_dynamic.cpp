#include<bits/stdc++.h>

#define MAX 109

using namespace std;

int binomialCoeff(int n, int k){
    int c[n+1][k+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i,k); j++){
            //base code
            if(j == 0 || j == i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    //cout << "\n" << "c[n][k] : " << c[n][k] << "\n";
    return c[n][k];
    
}

int lobb(int n, int m){
    return ((2 * m + 1) * binomialCoeff(2 * n, m + n)) / (m + n + 1);
}

int main(){
    int n = 5, m = 3;
    
    cout << "Lobbs number for (" << n << "," << m << ") is " << lobb(n,m);

    return 0;
}