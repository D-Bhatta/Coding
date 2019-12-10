""" ONP - Transform the Expression
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
at+bac++cd+^* """

n = int(input())

def rpn(expr):
    result = ""
    stack = []
    for i in range(len(expr)):
        if(expr[i] == '('):
            continue
        elif (expr[i] == ')'):
            """ pop from stack and add to end of string result"""
            temp = stack[-1]
            stack.__delitem__(-1)
            result = result + temp
        elif (expr[i] >= 'a' and expr[i] <= 'z'):
            """ add to end of string result"""
            result = result + expr[i]
        else:
            """ add operator to end of stack """
            stack.append(expr[i])
    return result

for i in range(n):
    expr = str(input())
    result = rpn(expr)
    print(result,end='\n')