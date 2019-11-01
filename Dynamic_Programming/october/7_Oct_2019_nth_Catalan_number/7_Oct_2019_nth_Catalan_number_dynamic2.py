#dynamic implementation of catalan with (n) complexity


def binomialCoeff(n,k):
    if(k > n-k):
        k = n-k
    res = 1

    for i in range(k):
        res *= (n-i)
        res /= (i+1)
    
    return res

def catalan(n):
    c = binomialCoeff(2*n,n)

    return c/(n+1)


#driver 
for i in range(11):
    print(" {}".format(int(catalan(i))))