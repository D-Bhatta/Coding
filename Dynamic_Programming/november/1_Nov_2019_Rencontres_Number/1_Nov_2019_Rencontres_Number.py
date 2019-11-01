# Recontres number

MAX = 100

def binomial_coeff(c,n,k):
    for i in range(0,n+1):
        for j in range(0, min(i,k) + 1):
            #base case
            if j == 0 or  j == i:
                c[i][j] = 1
            else:
                c[i][j] = c[i-1][j-1] + c[i-1][j]

def recontres_number(c,n,m):
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    #base case
    dp[0][0] = 1
    dp[1][0] = 0
    for i in range(n+1):
        for j in range(m+1):
            if j <= i:
                if j == 0 and i >1:
                    dp[i][j] = (i-1) * (dp[i-2][0] + dp[i - 1][0])
                else:
                    dp[i][j] = c[i][j] * dp[i-j][0]
    
    return dp[n][m]

#driver program
n = 7
m = 2
c = [[0 for i in range(MAX)] for j in range(MAX)]

binomial_coeff(c,n,m)
print ( "Rencontres number for n = " , n , " and m = " , m , " is : " , recontres_number(c,n,m))
n = 3 
m = 0
binomial_coeff(c,n,m)
print ( "Rencontres number for n = " , n , " and m = " , m , " is : " , recontres_number(c,n,m))
n = 3 
m = 1
binomial_coeff(c,n,m)
print  ("Rencontres number for n = " , n , " and m = " , m , " is : " , recontres_number(c,n,m))