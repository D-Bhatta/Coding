#dynamic implementation of edit distance

def editDistance(x,y,m,n):
    dp = [[0 for x in range(n+1)] for x in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):

            #if the first string is insert all chars of string second
            if(m == 0): dp[i][j] = j

            #if second string is empty, remove all chars of second string
            elif(n == 0): dp[i][j] = i

            #if last chars are same, move on 
            elif(x[m-1] == y[n-1]):
                dp[i][j] = dp[i-1][j-1]
            #store the minimum of all 3 operations
            else:
                dp[i][j] = 1+ min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])
    return dp[m][n]

#driver program
x = "saturday"
y = "sunday"

print("Distance = {}".format(editDistance(x,y,len(x),len(y))))