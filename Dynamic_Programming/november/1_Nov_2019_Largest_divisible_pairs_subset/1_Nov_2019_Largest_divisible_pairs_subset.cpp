#include<bits/stdc++.h>

using namespace std;


int largestSubset(int a[], int n){
    //sort array

    sort(a,a+n);


    int dp[n];

    // Since last element is largest, d[n-1] is 1 
    dp[n - 1] = 1; 


    for(int i = n - 2; i >= 0; i--){
        // Find all multiples of a[i] and consider 
        // the multiple that has largest subset 
        // beginning with it. 
        int mxm = 0;
        for(int j = i + 1; j < n; j++){
            if(a[j]%a[i] == 0){
                mxm = max(mxm,dp[j]);
            }
        }
        dp[i] = 1 + mxm;
    }

    return *max_element(dp,dp+n);
}

//driver code
int main(){
    int a[] = {1,3,6,13,17,18};

    int n = sizeof(a)/sizeof(a[0]);

    cout << "The largest subset is :" << largestSubset(a,n);
}