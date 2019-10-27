#dynamic erntringer

def erntringer(n,k):
    dp = [[0 for i in range(k+1)] for i in range(n+1)]

    #base cases
    dp[0][0] = 1

    for i in range(1,n+1):
        dp[i][0] = 0
    
    for i in range(1,n+1):
        for j in range(1,k+1):
            dp[i][j] = (dp[i][j-1] + dp[i-1][i-j])
    

    return dp[n][k]


n = 4
k = 3

print("Erntringer number for n = " , n , " and k = " , k , " is :" , erntringer(n,k))