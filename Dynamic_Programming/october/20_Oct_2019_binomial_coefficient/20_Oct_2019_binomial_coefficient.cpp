//naive binomial coefficient

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k){
    //BASE CASE
    if(k == 0 || k == n){
        return 1;
    }

    //recur
    return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);

}

//driver code
int main(){
    int n = 5, k = 2;

    cout << "Value of C("<<n<<", "<<k<<") is "<< binomialCoeff(n,k);
    return 0;
}