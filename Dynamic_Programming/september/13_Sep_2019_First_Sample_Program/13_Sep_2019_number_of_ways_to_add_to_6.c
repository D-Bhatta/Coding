/*
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is: 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1
*/

/*
Let’s think dynamically about this problem. So, first of all, we decide a state for the given problem. We will take a parameter n to decide state as it can uniquely identify any subproblem. So, our state dp will look like state(n). Here, state(n) means the total number of arrangements to form n by using {1, 3, 5} as elements.

Now, we need to compute state(n).
*/

/*
How to do it?
So here the intuition comes into action. As we can only use 1, 3 or 5 to form a given number. Let us assume that we know the result for n = 1,2,3,4,5,6 ; being termilogistic let us say we know the result for the
state (n = 1), state (n = 2), state (n = 3) ……… state (n = 6)

Now, we wish to know the result of the state (n = 7). See, we can only add 1, 3 and 5. Now we can get a sum total of 7 by the following 3 ways:

1) Adding 1 to all possible combinations of state (n = 6)
Eg : [ (1+1+1+1+1+1) + 1]
[ (1+1+1+3) + 1]
[ (1+1+3+1) + 1]
[ (1+3+1+1) + 1]
[ (3+1+1+1) + 1]
[ (3+3) + 1]
[ (1+5) + 1]
[ (5+1) + 1]

2) Adding 3 to all possible combinations of state (n = 4);

Eg : [(1+1+1+1) + 3]
[(1+3) + 3]
[(3+1) + 3]

3) Adding 5 to all possible combinations of state(n = 2)
Eg : [ (1+1) + 5]

Now, think carefully and satisfy yourself that the above three cases are covering all possible ways to form a sum total of 7;

Therefore, we can say that result for
state(7) = state (6) + state (4) + state (2)
or
state(7) = state (7-1) + state (7-3) + state (7-5)

In general,
state(n) = state(n-1) + state(n-3) + state(n-5)
*/
//So, our code will look like:

int solve_exponential(int n)
{
    //base case
    if(n<0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }

    return solve_exponential(n-1) + solve_exponential(n-3) + solve_exponential(n-5);
}

/*
Step 4 : Adding memoization or tabulation for the state
This is the easiest part of a dynamic programming solution. We just need to store the state answer so that next time that state is required, we can directly use it from our memory
*/
//Adding memoization to the above code


#define MAXN 100
//this function returns the number of  arrangements to form n
//INITITLIZE to -1
int dp[MAXN];
int solve_polynomial(int n)
{
    //base case
    if( n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    //checking if already calculated
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    //storing the result and returning
    return dp[n] = solve_polynomial(n-1) + solve_polynomial(n-3) + solve_polynomial(n-7);
}
