//dynamic implementation of gold mine problem
/*
Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

Examples:

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)

Input : mat[][] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
Output : 83


Create a 2-D matrix goldTable[][]) of the same as given matrix mat[][]. If we observe the question closely, we can notice following.

Amount of gold is positive, so we would like to cover maximum cells of maximum values under given constraints.
In every move, we move one step toward right side. So we always end up in last column. If we are at the last column, then we are unable to move right
If we are at the first row or last column, then we are unable to move right-up so just assign 0 otherwise assign the value of goldTable[row-1][col+1] to right_up. If we are at the last row or last column, then we are unable to move right down so just assign 0 otherwise assign the value of goldTable[row+1][col+1] to right up.
Now find the maximum of right, right_up, and right_down and then add it with that mat[row][col]. At last, find the maximum of all rows and first column and return it.

*/
#include<bits/stdc++.h>

using namespace std;
const int MAX  = 100;

// Returns maximum amount of gold that can be collected 
// when journey started from first column and moves 
// allowed are right, right-up and right-down 
int getMaxGold(int gold[][MAX], int m, int n){
    // Create a table for storing intermediate results 
    // and initialize all cells to 0. The first row of 
    // goldMineTable gives the maximum gold that the miner 
    // can collect when starts that row 
    int goldTable[m][n];

    memset(goldTable,0,sizeof(goldTable));


    //build the table from the last column
    for(int col  = n-1; col >= 0; col--){
        for(int row = 0; row < m; row++){
            // Gold collected on going to the cell on the right(->)
            int right = (col == n-1)? 0: goldTable[row][col+1];

            // Gold collected on going to the cell to right up (/) 
            int right_up = (row == 0 || col == n-1)? 0:goldTable[row-1][col+1];

            // Gold collected on going to the cell to right down (\)
            int right_down = (row == m-1 || col == n-1)? 0: goldTable[row+1][col+1];

            // Max gold collected from taking either of the 
            // above 3 paths
            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
        }
    }

    // The max amount of gold collected will be the max 
    // value in first column of all rows 
    int res = goldTable[0][0];

    for(int i = 1; i < m; i++){
        res = max(res, goldTable[i][0]);
    }
    return res;
}

//driver code
int main(){
    int gold[MAX][MAX] = { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4;

    cout << "Max gold is :" << getMaxGold(gold,m,n);

    return 0;
}