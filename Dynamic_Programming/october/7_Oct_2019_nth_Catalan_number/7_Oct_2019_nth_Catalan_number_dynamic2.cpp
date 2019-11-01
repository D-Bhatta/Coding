// dynamic solution with O(n) complexity

#include<bits/stdc++.h>
using namespace std;


//return binomial coefficient
int binomialCoeff(int n, int k){
    int res = 1;


    if(k > n - k){
        k = n - k;
    }

    //Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for(int i =0; i < k; ++i){
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

int catalan(int n){
    int c = binomialCoeff(2*n,n);

    return c/(n+1);
}

//driver program
int main(){
    for (int i = 0; i< 10; i++){
        cout << catalan(i) << " ";
    }
    return 0;
}