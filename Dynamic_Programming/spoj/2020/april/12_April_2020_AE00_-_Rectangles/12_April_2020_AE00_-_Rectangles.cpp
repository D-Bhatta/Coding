/* AE00 - Rectangles
#ad-hoc-1
Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.

Input
The first and only line of the standard input contains one integer N (1 <= N <= 10000).

Output
The first and only line of the standard output should contain a single integer equal to the number of different rectangles that Byteman can form using his squares.

Example
For the input data:

6
the correct result is:

8


Task author: Jakub Radoszewski. */

#include<bits/stdc++.h>
using namespace std;

int sqrs[100];

// function count_even
int count_even(int n){
    int result = 0;
    if(n%2 == 0){
        result = (n/2)-2;
    }
    else {
        result = ((n+1)/2)-3;
    }
    return result;
}
// function count_odd
int count_odd(int n){
    int result = 0;
    if(n%2 == 0){
        result = (n/2)-1;
    }
    else{
        result = ((n+1)/2)-1;
    }
    return result;
}




// function squares_odd(n)
int count_squares_even(int n){
    int root = (int) sqrt(n);
    int result = count_even(root);
    return result;
}
// function squares_even(n)
int count_squares_odd(int n){
    int root = (int) sqrt(n);
    int result = count_odd(root);
    return result;
}

// function rectanges
int rectangles(int n){
    int result,even,odd,squares_even,squares_odd;
    // count even numbers between 5 and n 
    even = count_even(n);
    // count odd numbers between 3 and n 
    odd = count_odd(n);
    // count even perfect squares between 5 and n
    squares_even = count_squares_even(n);
    // count odd perfect squares between 5 and n
    squares_odd = count_squares_odd(n);
    // remove odd squares from odd nums
    odd = odd - squares_odd;
    // remove even squares from even nums
    even = even - squares_even;
    cout << "  " << even << "  " << odd << "  " << squares_even  << "  " << squares_odd << endl;
    // add 1 for odd nums
    odd = 1 * odd;
    // add 2 for even nums
    even = 2 * even;
    // add 2 for odd perfect squares 
    squares_odd = 2 * squares_odd;
    // add 3 for even perfect squares
    squares_even = 3 * squares_even;
    // add 2 for 1 and 2 , 2 for 4 ,to result, followed by the rest
    result = 1 + 1 + 2 + odd + even + squares_even + squares_odd;
    // 
    // return result
    return result;
}


// main function
int main(){
    int n, result;
    // take input n
    cin >>  n;
    // call rectangles function(n) and store result
    result = rectangles(n);
    // print result
    cout << result << endl;
    // return
    return 0;
}
