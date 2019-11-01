//naive recursive catalan numbers

#include<bits/stdc++.h>
using namespace std;

int catalan(int n)
{
    int i;
    //base case 
    if(n<=1){
        return 1;
    }

    //catalan(n) is sum of catalan(i)*catalan(n-i-1) 
    int res = 0 ;
    for(i = 0; i < n; i++){
        res  += catalan(i)*catalan(n-i-i);
    }
    return res;
}

//driver program
int main(){
    for (int i = 0; i< 10; i++){
        cout << catalan(i) << " ";
    }
    return 0;
}