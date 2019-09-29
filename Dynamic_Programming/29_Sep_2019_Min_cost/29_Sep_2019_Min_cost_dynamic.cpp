//dynamic implementation of MinCost
#include<bits/stdc++.h>
#define r 3
#define c 3

int min(int x, int y, int z);

int minCost(int cost[r][c], int m, int n){
    int i, j;
    int [r][c];

    tc[0][0] = cost[0][0];

    //init first column of cost array
    for(i = 1; i <=m; i++){
        tc[i][0] = tc[i-1][0] + cost[i][0];
    }

    //init first row of tc array
    for (j = 0; j <=n; j++){
            tc[0][j] = tc[0][j-1] + cost[0][j];
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j+++){
            tc[i][j] = min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]) + cost[i][j];
        }
    }
    return tc[m][n];
}

//return min of 3 ints
int min(int x, int y, int z){
    if(x<y){
        return (x<z)? x:z;
    }
    else{
        return (y<z)? y:z;
    }
}

//driver program to test above functions
int main(){
    int cost [r][c] = {{1,2,3},{4,8,2},{1,5,3}};
    cout << "Min cost : " << minCost(cost, 2, 2);
    return 0;
}