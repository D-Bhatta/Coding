/* Take a input of a string.Then find frequency of a particular character.And if any character ( after a space ) is in small letter then change it in a capital letter.Finally add a special character after that string.Special character should come random basic for every dynamic input-output

Enter a string: I Love techmonastic Solution.

Input: e

Output:

Frequency of e = 4

Final string = I Love Techmonastic solution $.



Input: n

Output:

Frequency of n = 2

Final string = I Love Techmonastic Solution %. */
#include<bits/stdc++.h>
using namespace std;

char randomSpecial(){
    string in = "<>?!@#$%^&*+=";
    srand (time(NULL));
    int RandIndex = rand() % in.size();
    char out = in[RandIndex];
    return out;
}

// main function
int main(){
    string string1,string2,string3;
    size_t i,pos=0;
    int count=0;
    // capture string1 input
    getline(cin,string1);
    cout << string1;
    // capture string2 input
    getline(cin,string2);
    cout << string2;
    // find frequency of string2 in string1
    while(pos!=string::npos){
        i = string1.find(string2,pos);
        pos = i;
        if(i!=string::npos){
            ++count;
        }
        else{
            break;
        }
    }
    // print frequency
    cout << count;
    // iterate through string
    i = 0;
    while(i<string1.size()){
        // if string[i] == " " and islower(string[i+1])
        if(string1[i] == ' '  && islower(string1[i+1])){
            // upper((string[i+1]))
            string1[i+1] = toupper(string1[i+1]);
        }
        
    }
    
    // string3 = " " + random(specialCharactersList)
    string3.append(string1);
    string3.append(" ");
    string3.push_back(randomSpecial());
    // concatenate string1 and string 3
}
