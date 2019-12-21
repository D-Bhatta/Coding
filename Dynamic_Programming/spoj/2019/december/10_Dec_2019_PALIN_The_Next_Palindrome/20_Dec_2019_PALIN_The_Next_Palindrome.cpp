#include<bits/stdc++.h>
using namespace std;

bool all9s(string input){
    std::string::iterator it;
    for(it = input.begin();it!=input.end();++it){
        if(*it != '9'){
            return false;
        }
    }
    return true;
}

bool check_palindrome(string input){
    std::string::iterator it;
    std::string::reverse_iterator rit;
    it = input.begin();
    rit = input.rbegin();
    int mid = input.size()/2, counter = 0;
    bool flag = true;
    while(counter != mid){

        if(*it == *rit){
            ++it; ++rit;++counter;
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
        
    }
    return flag;
}

string generate_for_palindrome(string input){
    int n = input.size();
    int mid = n/2;
    string::iterator it;
    it = it + mid;
    string::reverse_iterator rit;
    rit = rit + mid;
   /*  while(*it == *rit){
        --it;--rit;
    } */
    if((distance(input.begin(),it) == distance(input.rend(), rit))){
       int k,sum=0;
       k = (*it - '0') + 1;
       *it = '0' + (k%10);
       int carry = k/10;
       ++it;++rit;
       while(it!= input.begin()){
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
    else{
        int k,sum=0;
        k = (*it - '0') + 1;       
        *it = '0' + (k%10);       
        int carry = k/10;
        *rit = *it;
        ++it;++rit;
       while(it!= input.begin()){
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

string generate_all9s(int n){
    string result;
    result.push_back('1');
    for(int i = 1; i <n; ++i){
        result.push_back('0');
    }
    result.push_back('1');
    return result;

}

string generate_palindrome(string input){
    if(input[0] == '9'){
        if(all9s(input)){
            return generate_all9s(input.size());
        }
    }
    else if(check_palindrome(input)){
        return generate_for_palindrome(input);
    }
    

}

int main(){
    string input;
    int n;
    cin >> n;
    while(n>0){
        cin >> input;
        cout << generate_palindrome(input) << endl;
        n--;
    }
    return 0;
}