#include<bits/stdc++.h>

using namespace std;

long long reverse(long long temp){
    long long rev =0;
    while(temp>0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    return rev;
}

long long int palin(long long int input){
    long long int result = 0, temp = (input+1);
    while(true){
        result = reverse(temp);
        if(temp == result){
            break;
        }
        ++temp;
    }

    return result;
}

int main(){
    int n;
    cin >> n;
    long long int input;
    while(n>0){
        cin >> input;
        long long int result =  palin(input);
        cout << result << endl;
        --n;
    }
}