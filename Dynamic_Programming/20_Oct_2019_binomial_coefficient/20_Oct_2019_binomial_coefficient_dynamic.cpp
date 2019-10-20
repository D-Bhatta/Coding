#include<bits/stdc++.h>

using namespace std;

//return min of2 ints
int min(int a, int b){
    return (a>b)? a:b;
}

int binomialCoeff(int n, int k){
    int c[n+1][k+1];
    int i, j;

    for (i = 0; i <=  n ; i++){
        for(j = 0; j <= min(i,k); j++){
            //base case
            if(j == 0 || j == i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
            
        }
    }
    return c[n][k];
}

//driver code
int main(){
    int n = 5, k = 2;

    cout << "Value of C("<<n<<", "<<k<<") is "<< binomialCoeff(n,k);
    return 0;
}