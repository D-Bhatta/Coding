/* FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.
Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output

For each integer n given at input, display a line with the value of n!
Example
Sample input:

4
1
2
5
3

Sample output:

1
2
120
6

 */

#include<bits/stdc++.h>

using namespace std;

size_t multiply(int n, int num[], size_t size_current){
    /* n = multiplyt by. num = multiply to. and size of num. */
    //to store multiplication result
    int result = 0;
    //to store carry
    int carry = 0;
    size_t temp = size_current;
    //multiply current set of digits in num by n
    for(int i = 0; i <temp; i++){
        result = (num[i] * n) + carry;
        num[i] = result%10;
        carry = result/10;
    }
    //add carry digits to num
    while(carry>0){
        ++size_current;
        num[size_current-1] = carry%10;   
        carry = carry/10;
    }

    /* return current size of array */
    return size_current;
}

int factorial(int n){
    size_t size_array = 200, array_current = 1;
    int fact[size_array]; fact[0] = 1;
    //loop till n
    for(int i = 2; i <=n; i++){
        //multiply each num by factorial;
        array_current = multiply(i,fact,array_current);
    }


    //print result using array current
    for(int i = array_current-1; i >=0; --i){
        cout << fact[i];
    }
    return 0;
}


int main(){
    int n;
    cin >> n;
    int input;
    while(n>0){
        cin >> input;
        factorial(input);
        cout << endl;
        --n;
    }

    return 0;
}