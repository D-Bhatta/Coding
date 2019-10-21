#naive eulerian

def eulerian(n,m):
    if m >= n or n == 0:
        return 0
    if m == 0:
        return 1
    
    return ((n-m)*eulerian(n-1,m-1))+((m+1)*eulerian(n-1,m))


#driver code

n = 3
m = 1
print("Eulerian(",n,",", m, ") is ", eulerian(n,m))