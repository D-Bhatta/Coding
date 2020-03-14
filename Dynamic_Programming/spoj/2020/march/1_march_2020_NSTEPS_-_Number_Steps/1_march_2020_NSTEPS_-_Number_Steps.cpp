/* NSTEPS - Number Steps
#ad-hoc-1
Starting from point (0,0) on a plane, we have written all non-negative integers 0, 1, 2,... as shown in the figure. For example, 1, 2, and 3 has been written at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.

 

Illustration


You are to write a program that reads the coordinates of a point (x, y), and writes the number (if any) that has been written at that point. (x, y) coordinates in the input are in the range 0...10000.

 

Input
The first line of the input is N, the number of test cases for this problem. In each of the N following lines, there is x, and y representing the coordinates (x, y) of a point.

 

Output
For each point in the input, write the number written at that point or write No Number if there is none.

 

Example
Input:
3
4 2
6 6
3 4

Output:
6
12
No Number */
#include<bits/stdc++.h>
using namespace std;
int n_steps(int x, int y){
    if((x < y)||(y<(x-2)) || (y==(x-1))){
        return -1;
    }
    bool odd_x = (x%2), odd_y = (y%2);
    if(odd_x != odd_y){
        return -1;
    }    
    if(odd_x == true){
        int sum = x + y;
        sum -= 1;
        return sum;
    }
    else
    {
        return (x+y);
    }
    
    return 0;
}
int main(){
    int n;
    int x,y;
    cin >> n;
    while(n > 0){
        cin >> x;
        cin >> y;
        int result = n_steps(x,y);
        if (result == -1){
            cout << "No Number" <<endl;
        }
        else
        {
            cout << result << endl;
        }
        
        --n;
    }

}