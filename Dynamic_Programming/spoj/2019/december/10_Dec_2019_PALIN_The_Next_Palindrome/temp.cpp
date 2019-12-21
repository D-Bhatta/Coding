#include<bits/stdc++.h>
using namespace std;

string generate_for_palindrome(string input){
    int n = input.size();
    int mid = n/2;
    // cout << endl << mid << endl;
    string::iterator it;
    it = input.begin();
    it = it + mid;
    // cout << endl << *it << endl;
    string::reverse_iterator rit;
    rit = input.rbegin();
    rit = rit + mid;
    // cout << endl << *rit << endl;
    if(n%2 == 1){
       int k,sum=0;
       k = (*it - '0') + 1;
       *it = '0' + (k%10);
       int carry = k/10;
       ++it;++rit;
       if(rit == (input.rend()+1)){
                char kk = ( '0' + carry);        
                input = kk + input;
                *it = *rit;
       cout << endl << *it << endl;
       cout << endl << *rit << endl;
            }
       while(rit!=(input.rend()+1)){
           k = (*rit - '0');           sum = k + carry;           k = sum%10;           carry = sum/10;
           *rit = '0' + k;
           *it = *rit;
           ++it;++rit;
           if(rit == (input.rend()+1)){
                char kk = ( '0' + carry);        
                input = kk + input;
                *it = *rit;
            }
       }

        
    }
    else{
        int k,sum=0;
        k = (*rit - '0') + 1;       
        *rit = '0' + (k%10);       
        int carry = k/10;
        *it = *rit;
        ++it;++rit;
       while(rit!= (input.rend()+1)){
           k = (*it - '0');           sum = k + carry;           k = sum%10;           carry = sum/10;
           *it = '0' + k;
           *rit = *it;
           ++it;++rit;
           if(it == input.begin()){
                char kk = ( '0' + carry);        
                input = kk + input;
                *rit = *it;
            }
       }
        
    }


    return input;
}
int main(){
    /* string a,b;
    a.push_back('9');
    string::iterator it;
    it =a.begin();
    int k;
    k = (*it - '0') + 1;
    *it = '0' + (k%10);
    int carry = k/10;
    if(it == a.begin()){
        char kk = ( '0' + carry);
        a = kk + a;
    }
    
    cout << endl << a << endl; */
    string input;
    cin >> input;
    cout << generate_for_palindrome(input) << endl;
}
