/* PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed) */

#include<bits/stdc++.h>

using namespace std;



bool isprime(int x){
    /* check if prime or not */
    if(x == 1 || x == 0){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int primesgen(int x, int y){
    int i = 0;
    for(i=x; i <=y; i++){
        if(isprime(i)){
            cout << i << endl;
        }
    }
    return 0;
}

int main(){
    int test_cases;
    int x = 0, y = 0;
    cin >> test_cases;
    for(int i = 0; i < test_cases; i++){
        cin >> x;
        cin >> y;
        primesgen(x,y);
    }
    return 0;
}