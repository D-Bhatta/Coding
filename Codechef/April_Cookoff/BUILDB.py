""" Bodybuilder Problem Code: BUILDB
Add problem to Todo list
Submit
Read problems statements in Mandarin Chinese, Russian, and Bengali as well.
After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.

On any regular day, Chef does N exercises at times A1,A2,…,AN (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN units. In the period between two consecutive exercises, his muscles relax R units of tension per minute.

More formally, Chef's tension is described by a number x. Before any workouts, x=0. When he does a workout at time Ai, the tension x instantly increases by Bi. Between workouts, the number x decreases by R units per minute, maximized with 0.

Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains 3 lines of input.
The first line will contain 2 space-separated integers N,R, number of timestamps at which Chef performs his exercise, and units of tension relaxed per minute.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output:
For each testcase, output in a single line the maximum amount of tension Chef will have in his muscles.

Constraints
1≤T≤10
1≤N≤5⋅104
1≤R,Bi≤105
1≤Ai≤109
Ai−1<Ai, for all 2≤i≤N
Sample Input:
3
1 2
10
10
2 2
10 11
10 10
3 1
1 2 3
1 2 3
Sample Output:
10
18
4
Explanation:
Test Case 1: Since there is only 1 exercise, the maximum tension is equal to the tension provided by that exercise, i.e, 10 units.

Test Case 2: At time t=10, Chef has 10 units of tension.

From t=10 to t=11, his muscles releases 2 unit of tension and at t=11, he further gains 10 units of tension to have total of 10−2+10=18 units of tension.

So the maximum tension Chef feels in his muscles is 18 units.

Test Case 3: At time t=1, Chef has 1 unit of tension.

From t=1 to t=2, his muscles releases 1 unit of tension and at t=2, he further gains 2 units of tension to have total of 1−1+2=2 units of tension.

From t=2 to t=3, his muscles releases 1 unit of tension and at t=3, he further gains 3 units of tension to have total of 2−1+3=4 units of tension.

So the maximum tension Chef feels in his muscles is 4 units. """

""" 
First of all

It takes some test cases

Now, each test case has n and r

R is the amount of tension lost per minute. So total tension lost is R * total
time between the times of exercising.

There are N times of exercising, and N tension

So, tension T is the simple sum of all N tension.

There will be n-1 minutes of rest.

That will be calculated by subtracting a[i+1] - a[i-1] for each i in n.
"""

def minutes_of_rest(list_min: list, n):
    rested = 0
    for i in range(n):
        if i+1 == n:
            break
        rested = rested + (list_min[i+1] - list_min[i])
    return rested

num_cases = int(input())
# input cases
# for each case
for i in range(num_cases):
# input n and r
    n, r = map(int, input().strip().split())
    # input n a
    a = list(map(int, input().strip().split()))
    # input n b and calculate sum of b using lambda and reduce and int fun as T
    total_t = sum(map(int, input().strip().split()))
    # calculate differences between n a using loop and mult with r
    total_r = r * minutes_of_rest(a,n)
    # subtract total r from T and return
    print(total_t - total_r)
