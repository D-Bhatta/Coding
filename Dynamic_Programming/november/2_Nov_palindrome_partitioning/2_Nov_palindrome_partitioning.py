from sys import maxsize

def minPalPartition(str1):
    n = len(str1)

    c = [0 for i in range (n+1)]
    p = [[False for i in range(n+1)] for j in range(n+1)]


    for i in range(n):
        p[i][i] = True
    
    for l in range(2,n+1):
        for i in range(n-l+1):
            j = i+l-1
            if l == 2:
                p[i][j] = (str1[i] == str1[j])
            else:
                p[i][j] = (str1[i] == str1[j]) and p[i+1][j-1]
    
    for i in range(n):
        if p[0][i] == True:
            c[i] == 0
        else:
            c[i] = maxsize
            for j in range(i):
                if(p[j+1][i] == True and c[j]+1 < c[i]):
                    c[i] = c[j] + 1
    
    return c[n-1]

str1 = "ababbbabbababa"
print("Min cuts needed for Palindrome Partitioning is",minPalPartition(str1))