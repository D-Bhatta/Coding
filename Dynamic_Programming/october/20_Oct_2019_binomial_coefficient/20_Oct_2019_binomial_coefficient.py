#naive binomialcoeff
def binomialCoeff(n,k):
    
    #base case
    if k == 0 or k == n:
        return 1
    
    #Recursion
    return binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k)

#driver code
n = 5
k = 2

print("The binomial coeff of {} and {} is {}".format(n,k,binomialCoeff(n,k)))