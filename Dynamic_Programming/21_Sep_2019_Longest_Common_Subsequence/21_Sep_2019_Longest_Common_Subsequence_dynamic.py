#dynamic programming implementtion of LCS

def lcs(x,y):
    #len of strings
    m = len(x)
    n = len(y)

    #declare the array for storing dp values
    l = [[None]*(n+1) for i in range(m+1)]
    #Build l[m+1][n+1] in bottom up fashiion
    for i in range(m+1):
        for j in range(n+1):
            if(i == 0 or j == 0):
                l[i][j] = 0
            elif x[i-1] == y[j-1]:
                l[i][j] = l[i-1][j-1] + 1
            else:
                l[i][j] = max(l[i-1][j],l[i][j-1])
    
    return l[m][n]

#Driver code for the above function:
x = "AGGTAB"
y = "GXTXAYB"

print("Length of LCS is {}".format(lcs(x,y)))