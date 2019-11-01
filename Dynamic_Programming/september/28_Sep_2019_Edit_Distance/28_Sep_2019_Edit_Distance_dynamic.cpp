//dynamic solution to edit distance

#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z){
    return min(min(x,y),z);
}


int editDistance(string x, string y, int m, int n){
    //create a table to store sub problem results
    int dp[m+1][n+1];

    //fill d[][] in bottom up manner
    for(int i = 0; i <= m; i++){
        for(int j = 0; j<=n; j++){
            //if first string is empty insert all character of second string
            if(i == 0) {
                dp[i][j] = j;
            }
            //if second string is empty remove all characters of first string
            else if{
                dp[i][j] = i;
            }//last character aare same, ignore them
            else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {//consider the minimum of all 3 operations
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

//driver program

int main(){
    string x = "sunday";
    string y = "saturday";

    cout << "Distance" << editDistance(x,y,x.length(),y.length());

    return 0;
}