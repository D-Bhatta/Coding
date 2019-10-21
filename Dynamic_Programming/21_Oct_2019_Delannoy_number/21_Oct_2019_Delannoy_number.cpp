#include<bits/stdc++.h>

using namespace std;

int dealnnoy(int n, int m){
    //base case
    if(n == 0 || m == 0){
        return 1;
    }

    //recursive step
    return dealnnoy(m-1, n) + dealnnoy(m-1, n-1) + dealnnoy(m, n-1);
}

//driver program

int main(){
    int n = 3, m  = 4;

    cout << "Dealnnoy(3,4) = " << dealnnoy(n,m);

    return 0;
}