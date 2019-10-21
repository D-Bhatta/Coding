#dynamic eulerian

def eulerian(n,m):
    dp = [[0 for i in range(m+1)] for i in range(n+1)]

    for i in range(1,n+1):
        for j in range(0, m+1):
            if i > j:
                if j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = (((i-j)*dp[i-1][j-1])+((j+1)* dp[i-1][j]))
    return dp[n][m]


#driver code

n = 3
m = 1
print("Eulerian(",n,",", m, ") is ", eulerian(n,m))