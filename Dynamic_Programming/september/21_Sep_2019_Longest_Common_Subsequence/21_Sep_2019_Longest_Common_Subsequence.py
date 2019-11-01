'''Longest common subsequence'''

#naive LCS

def lcs(x,y,m,n):
    if m == 0 or n == 0:#return 0 if beginning of string is reached
        return 0
    if x[m-1] == y[n-1]:
        return 1 + lcs(x,y,m-1,n-1)
    else:
        return max(lcs(x,y,m,n-1),lcs(x,y,m-1,n))

#Driver function to test the above function

x = "AGGTAB"
y = "GXTXAYB"

print("Length of lcs is {}".format(lcs(x,y,len(x),len(y))))