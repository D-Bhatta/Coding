//dynamic solution to catalan numbers

#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    int table[n+1];
    //base case

    table[0] = table[1] = 1;

    //fill in bottom up manner

    for(int i = 2; i <= n; i++){
        table[i] = 0;
        for(int j = 0; j < i; j++){
            table[i] += table[j] * table[i-j-1];
        }
    }

    return table[n];
}

//driver program
int main(){
    for (int i = 0; i< 10; i++){
        cout << catalan(i) << " ";
    }
    return 0;
}