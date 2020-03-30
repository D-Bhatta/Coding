/* 
FASHION - Fashion Shows
#ad-hoc-1
A fashion show rates participants according to their level of hotness. Two different fashion shows were organized, one for men and the other for women. A date for the third is yet to be decided ;) .

Now the results of both fashion shows are out. The participants of both the fashion shows have decided to date each other, but as usual they have difficuly in choosing their partners. The Maximum Match dating serive (MMDS) comes to their rescue and matches them in such a way that that maximizes the hotness bonds for all couples.

If a man has been rated at hotness level x and a women at hotness level y, the value of their hotness bond is x*y.

Both fashion shows contain N participants each. MMDS has done its job and your job is to find the sum of hotness bonds for all the couples that MMDS has proposed.

Input
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of 3 lines:

The first line contains a single integer N (1 <= N <= 1000).
The second line contains N integers separated by single spaces denoting the hotness levels of the men.
The third line contains N integers separated by single spaces denoting the hotness levels of the women.
All hotness ratings are on a scale of 0 to 10.

Output
For each test case output a single line containing a single integer denoting the sum of the hotness bonds for all pairs that MMDS has proposed.

Example
Input:
2
2
1 1
3 2
3
2 3 2
1 3 2

Output:
5
15 */
#include<bits/stdc++.h>
using namespace std;

// function hotness(men,women,n)
int hotness(vector<int> men, vector<int> women, int n, int hotness_matrix[11][11]){
    int sum = 0;
    // loop i=0 till n-1
    for(int i = 0; i <n; i++){
        // take hotness_matrix[men[i]][women[i]] and add to sum
        sum = sum+hotness_matrix[men[i]][women[i]];
    }
        
    // return sum
    return sum;
}


// fashion shows
// main function
int main(){
    int t,n,temp,result;
    vector<int> men, women;
    // create hotness matrix
    int hotness_matrix[11][11];
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            hotness_matrix[i][j] = i*j;
        }
    }
    // take input t
    cin >> t;
    // loop till t==0
    while(t>0){
        // reinit variables
        men.clear();
        women.clear();
        // take input n
        cin >> n;
        // insert into array men
        for(int i = 0; i <n; ++i){
            cin >> temp;
            men.push_back(temp);
        }
        // insert into array women
        for(int i = 0; i <n; ++i){
            cin >> temp;
            women.push_back(temp);
        }
        // sort them in descending order
        sort(men.begin(), men.end(), greater<int>());
        sort(women.begin(), women.end(), greater<int>());
        // call function hotness(men,women,n) and store result
        result = hotness(men,women,n,hotness_matrix);
        // print result
        cout << result << endl;
        // decrement t
        --t;
    }
    
    // return 0
    return 0;
}

