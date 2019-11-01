//naive coin change
#include<bits/stdc++.h>

//returns the sum of ways we can sum S[0...m-1] coins to get sum n
int count(int s[], int m, int n){
    //if n is 0, there is only one solution
    if(n == 0){
        return 1;
    }
    //if n is less than 0 then no solution exists
    if (n<0){
        return 0;
    }

    //If there are no coins and n      // is greater than 0, then no     // solution exist 
    if(m<=0 && n>=1){
        return 0;
    }
    //else count the number of solutionns that exist
    // count is sum of solutions (i)  
    // including S[m-1] (ii) excluding S[m-1] 
    return count(s, m-1, n) + count(S,m,n-s[m-1])
}

//driver program to test above function
int main(){
    int n = 4;
    int arr[]= {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout <<"count: " << count(arr,m,4);
    return 0;
}
