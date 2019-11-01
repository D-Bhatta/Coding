#naive recursive catalan

def catalan(n):
    #base case
    if(n<=0):
        return 1
    
    # Catalan(n) is the sum of catalan(i)*catalan(n-i-1)
    res = 0
    for i in range(n):
        res += catalan(i) * catalan(n-i-1)
    
    return res

#driver 
for i in range(11):
    print(" {}".format(catalan(i)))