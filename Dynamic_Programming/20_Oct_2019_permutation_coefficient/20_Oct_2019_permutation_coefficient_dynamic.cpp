#include<bits/stdc++.h>
using namespace std;
int permutationCoeff(int n, int k){
    int fact[n+1];

    //base
    fact[0] = 1;

    for(int i = 1; i <= n; i++){
        fact[i] = i * fact[i-1];
    }
    // P(n,k) = n! / (n - k)! 
    return int (fact[n]/fact[n-k]);
}

//driver 
int main(){
    int n = 10, k = 2;

    cout << "Permuattion coeff of " << n << " and " << k << " is " << permutationCoeff(n,k);

    return 0;
}