""" Chocolate Monger Problem Code: CM164364
Add problem to Todo list
Submit
Read problems statements in Mandarin Chinese, Russian, and Bengali as well.
There are n chocolates, and you are given an array of n numbers where the i-th number Ai is the flavour type of the i-th chocolate. Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least x number of chocolates for her little brother.

Find the maximum possible number of distinct flavour types Sebrina can have.

Input:
The first line contains an integer T --- the number of test cases.

The first line of each test case consists of two integers n, x - The number of chocolates Sabrina has and the number of chocolates she has to save for her brother, respectively.

The second line contains n integers A1,…,An, where the i-th chocolate has type Ai.

Output:
For each test case, output a single integer denoting the maximum possible number of distinct chocolate flavours Sabrina can eat.

Constraints
1≤T≤10
1≤x≤n≤2⋅10^5

1≤Ai≤10^9
Sum of n over all test cases do not exceed 2⋅10^5
Sample Input:
3
2 1
1 2
4 2
1 1 1 1
5 3
50 50 50 100 100

Sample Output:
1
1
2
EXPLANATION:
In the first test case, she can give any 1 chocolate to her brother and can have the other for herself resulting in 1 flavour type for Sebrina.
"""

num_cases = int(input())
# input cases
# for each case
for i in range(num_cases):
    n, x = map(int, input().strip().split())
    # if n == x, print 0
    if n == x:
        print(0)
        continue
    # take a set of all the chocolate flavors and get len i of set
    i = len(set(map(int, input().strip().split())))
    unique = 0
    # if i < n - x, then unique = i, if there is plenty
    if i < (n-x):
        unique = i
    # if i == N - x, then unique = n-x, if there is just enough
    elif i == n-x :
        unique = n-x
    # if i > n-x, then unique = n-x, if there is less than adequate, then it is
    # the difference of n and x
    else:
        unique = n-x
    # print unique
    print(unique)