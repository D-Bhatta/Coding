#dynamic lobb

def binomialCoeff(n , k):
    c = [[0 for i in range(k+1)] for i in range(n+1)]

    for i in range(0,n+1):
        for j in range(0,min(i,k) + 1):
            if j == 0 or j == i:
                c[i][j] = 1
            else:
                c[i][j] = c[i-1][j-1] + c[i-1][j]
    

    return c[n][k]


def lobb(n,m):
    return (((2 * m+1) * binomialCoeff(2*n,m+n)) / (m+n+1))


#driver code

n = 5
m = 3

print("Lobbs number for (" , n , "," , m , ") is " , lobb(n,m))
