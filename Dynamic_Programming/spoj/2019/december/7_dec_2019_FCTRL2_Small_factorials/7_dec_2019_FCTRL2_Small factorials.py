""" FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.
Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output

For each integer n given at input, display a line with the value of n!
Example
Sample input:

4
1
2
5
3

Sample output:

1
2
120
6

"""
def factorial(n):
    """ return the factorial """
    result = 1
    for i in range(2,n+1):
        result = result * i
    
    return result

#get the number of inputs as int
num = int(input())
for i in range(num):
    n = int(input())
    print(factorial(n), end='\n')