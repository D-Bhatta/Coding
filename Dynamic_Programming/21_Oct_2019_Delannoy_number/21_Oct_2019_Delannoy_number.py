#dealnnoy naive

def dealnnoy(n,m):
    if n == 0 or m == 0:
        return 1

    return dealnnoy(m-1,n) + dealnnoy(m-1,n-1) + dealnnoy(m,n-1)

#driver code

n = 3

m = 4

print("Dealnnoy ", n, " ,", m," is ", dealnnoy(n,m) )