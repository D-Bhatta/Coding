#dynamic binomial coeff

def binomialCoeff(n,k):
    c = [[0 for i in range(k+1)] for i in range(n+1)]

    for i in range(n+1):
        for j in range(min(i,k)+1):
            if j == 0 or j == i:
                c[i][j] = 1
            else:
                c[i][j] = c[i-1][j-1] + c[i-1][j]
    
    return c[n][k]

#driver code
n = 5
k = 2

print("The binomial coeff of {} and {} is {}".format(n,k,binomialCoeff(n,k)))