//naive implementation of min cost
#include<bits/stdc++.h>
using namespace std;
#define r 3
#define c 3

//min func declaration:
int min(int x, int y, int z);

//Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]
int minCost(int cost[r][c], int m ,int n){
    if(n < 0 || m < 0){
        return -1;
    }
    else if(m == 0 && n == 0){
        return cost[m][n];
    }
    else {
        return cost[m][n] + min( minCost(cost,m-1,n-1), minCost(cost,m-1,n), minCost(cost, m,n-1));
    }
}

//an utility function that returns min of 3 ints
int min (int x, int y, int z){
    if(x < y){
        return (x < z)? x : z;
    }
    else
    {
        return (y < z)? y : z;
    }
    
}

//driver func
int main(){
    int cost[r][c] = { {1,2,3},
                        {4,8,2},
                        {1,5,3}
                    };
    cout << "Min Cost:" << minCost(cost,2,2);
    return 0;
}