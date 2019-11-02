#martix CHAIN Mult
from sys import maxsize

def matrixChainOrder(p,n):

    m = [[0 for i in range(n)] for j in range(n)]

    for i in range(1,n):
        m[i][i] = 0

    for l in range(2,n):
        for i in range(1,n-l+1):
            j = i+l-1
            m[i][j] = maxsize
            for k in range(i,j):
                m[i][j] = min((m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]), m[i][j])
            
        
    
    return m[1][n-1]

arr = [1,2,3,4]
size = len(arr)

print("Minimum number of multiplications is " + str(matrixChainOrder(arr, size))) 
