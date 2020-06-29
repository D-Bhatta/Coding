/* 0,0,550,275,1100,550,1650,825,2200,1100,2750,1375,3300,1650,3850,1925,4400,2200 */
#include<bits/stdc++.h>
using namespace std;

int fin_550(int n){
    // div n by 2 -> q
    int q = n/2;
    // mult 550 by q -> num
    int num = q * 550;
    // return num
    return num;
}

// main function
int main(){
    int n, output = 0;
    while(true){
        cin >> n;
        if(n <= 0){
            exit(1);
        }
        // if n = (1,2), return 0
        if (n == 1 || n == 2){
            output = 0;
        }
        // if n %2 == 1, fin_550(n)
        if (n % 2 == 1){
            output = fin_550(n);
        }
        // else find_550(n-1)/2
        else{
            output = (fin_550(n-1))/2;
        }
        cout << output << endl;
    }
}

