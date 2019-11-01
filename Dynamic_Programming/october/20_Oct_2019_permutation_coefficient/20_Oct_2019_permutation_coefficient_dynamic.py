# dynamic permutation coeff

def permutationCoeff(n,k):
    fact = [0 for x in range(n+1)]
    fact[0] = 1

    for i in range(1,n+1):
        fact[i] = fact[i-1] * i
    
    return int(fact[n]/fact[n-k])

#driver code

n = 10
k = 2

print("Permuattion coeff of {} and {} is {}".format(n,k,permutationCoeff(n,k)))