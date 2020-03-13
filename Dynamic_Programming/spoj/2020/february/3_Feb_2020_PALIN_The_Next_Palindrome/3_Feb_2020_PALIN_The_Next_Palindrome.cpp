#include<bits/stdc++.h>
using namespace std;

/* Solution visited at:
https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/ */
bool areAll9s(string input_string){
    size_t input_size= input_string.size();
    for(int i =0; i < input_size; ++i){
        if(input_string[i] != '9'){
            return false;
        }
    }
    return true;
}

string generate_next_palindrome(string input_string){
    size_t input_size = input_string.size();
    // middle elements(s)
    int mid = input_size/2;
    // to check if copy of left is smaller than right
    bool left_smaller = false;
    // end of left side is always mid - 1
    int i = mid - 1;
    // beginning of right side depends on whether n is odd or even
    int j = (input_size%2)? mid+1 : mid;
    // ignore the same middle digits
    for(;i>=0 && input_string[i] == input_string[j];--i,++j){}

    /* check if the middle digits need to be incremented or not or 
    copying left side is not sufficient */
    if(i< 0 || input_string[i] < input_string[j]){
        left_smaller = true;
    }

    // mirror left side on right side
    while(i >=0){
        input_string[j] = input_string[i];
        ++j;
        --i;
    }

    // handle the case where middle digits must be incremented
    if(left_smaller == true){
        // carry stores the increment to the digits
        int carry = 1;
        // position i to the end of the left side
        i = mid - 1;
        // if there are odd digits then increment the middle digits and store the carry
        if(input_size%2 == 1){
            // take the num value of the char at mid
            int temp = input_string[mid] - '0';
            // increment num value by carry
            temp = temp + carry;
            // store the MSB digit of the num value in carry
            carry = temp /10;
            // store the LSB digit of the num value in temp
            temp %= 10;
            // store back num value as string
            input_string[mid] = temp + '0';
            // position j at the beginning of the right side
            j = mid + 1;
        }
        else{
            // position j at the beginning of the right side
            j = mid;
        }
        /* add 1 to the right most digit of the left side,
        propagate the carry toward the MSb digit and simultenously 
        mirror the left side to the right side */
        while (i >= 0){
            // take the value of the character at i
            int temp = input_string[i] - '0';
            // add carry num value, initially incrementing it by 1
            temp += carry;
            // store MSBs except for units digit in carry
            carry = temp / 10;
            // store units digit in temp
            temp = temp%10;
            // store temp value at input_string[i] as string
            input_string[i] = temp + '0';
            // mirror left side to right side
            input_string[j++] = input_string[i--];
        }
    }
    return input_string;
}

string generate_palindrome(string input_string){
    int i;
    size_t input_size= input_string.size();
    if(areAll9s(input_string)){
        string output = "";
        output.append("1");
        for(i = 1; i < input_size; ++i){
            output.append("0");
        }
        output.append("1");
        return output;
    }
    else
    {
        return generate_next_palindrome(input_string);
    }
    
    return input_string;
}




int main(){
    string input_string;
    int n;
    cin >> n;
    while(n>0){
        cin >> input_string;
        cout <<generate_palindrome(input_string) << endl;
        --n;
    }
    return 0;
}