#include<bits/stdc++.h>
using namespace std;

int count(int s[], int m, int n){
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1];

    memset(table,0,sizeof(table));

    //basecase
    table[0] = 1;

    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i = 0; i < m; i ++){
        for(int j =s[i]; j <= n; j++){
            table[j] += table[j-s[i]];
        }
    }
    return table[n];
}

//driver program to test above function
int main(){
    int n = 4;
    int arr[]= {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout <<"count: " << count(arr,m,4);
    return 0;
}