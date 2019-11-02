#jacobsthal dynamic

def jacobsthal(n):
    dp = [0 for i in range(n+1)]

    dp[0] = 0
    dp[1] = 1

    for i in range(2,n+1):
        dp[i] = dp[i-1] + dp[i-2] * 2
    
    return dp[n]



def jacobsthal_lucas(n):
    dp = [0 for i in range(n+1)]

    dp[0] = 2
    dp[1] = 1

    for i in range(2,n+1):
        dp[i] = dp[i-1] + dp[i-2] * 2
    
    return dp[n]

n = 5

print ( "Jacobsthal for n = " , n , " is :" , jacobsthal(n))

print ( "Jacobsthal-Lucas for n = " , n , " is :" , jacobsthal_lucas(n))

n = 17

print ( "Jacobsthal for n = " , n , " is :" , jacobsthal(n))

print ( "Jacobsthal-Lucas for n = " , n , " is :" , jacobsthal_lucas(n))