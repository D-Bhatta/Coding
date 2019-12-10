/* ONP - Transform the Expression
#stack
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

Input
t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output
The expressions in RPN form, one per line.
Example
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^* */

#include<bits/stdc++.h>

using namespace std;

string rpn(string input){
    string result;
    std::string::iterator it;
    it = input.begin();
    /* create a stack to store operators*/
    stack <char> ops;
    for(it = input.begin(); it != input.end(); ++it){
        if(*it == '('){
            continue;
        }
        else if(*it == ')'){
            /* pop from operator from stack and add it to string*/
            if(!ops.empty()){
                char temp = ops.top();
                ops.pop();
                result.push_back(temp);
            }
        }
        else if(*it >= 'a' && *it <= 'z'){
            /* add to string */
            result.push_back(*it);
        }
        else{
            /* add operator to stack */
            ops.push(*it);
        }
    }

    return result;
}

int main(){
    int n;
    string input;
    cin >> n;
    while(n>0){
        cin >> input;
        string result = rpn(input);
        cout << result << endl;
        --n;

    }
    return 0;
}